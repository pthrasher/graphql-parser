require_relative 'test_helper'

class VisitorTest < Minitest::Test
  class NameVisitor < GraphQL::Visitor
    attr_accessor :nodes

    def initialize
      @nodes = []
    end

    def method_missing(name, node)
      @nodes << name
    end
  end

  def test_visiting_basic_query
    v = NameVisitor.new
    v.accept(GraphQL::Parser.parse('{ field }'))
    assert_equal [
      :visit_document,
      :visit_operation_definition,
      :visit_selection_set,
      :visit_field,
      :visit_name,
      :end_visit_name,
      :end_visit_field,
      :end_visit_selection_set,
      :end_visit_operation_definition,
      :end_visit_document
    ], v.nodes
  end

  class SkipChildrenVisitor < GraphQL::Visitor
    def visit_document(node)
      @nodes << :visit_document
      GraphQL::SKIP_CHILDREN
    end
  end

  def test_skip_children
    v = SkipChildrenVisitor.new
    v.accept(GraphQL::Parser.parse('{ field }'))
    assert_equal [
      :visit_document,
      :end_visit_document
    ], v.nodes
  end

  class NodeVisitor < GraphQL::Visitor
    attr_accessor :nodes

    def initialize
      @nodes = []
    end

    def method_missing(name, node)
      @nodes << node
    end
  end

  def test_skip_children
    v = NodeVisitor.new
    v.accept(GraphQL::Parser.parse('{ field }'))

    assert_equal GraphQL::Document, v.nodes[0].class
    assert_equal 1, v.nodes[0].definitions_size

    assert_equal GraphQL::OperationDefinition, v.nodes[1].class
    assert_equal 'query', v.nodes[1].operation
    assert_nil v.nodes[1].name
    assert_equal GraphQL::SelectionSet, v.nodes[1].selection_set.class
    assert_equal 0, v.nodes[1].variable_definitions_size
    assert_equal 0, v.nodes[1].directives_size

    assert_equal GraphQL::SelectionSet, v.nodes[2].class
    assert_equal 1, v.nodes[2].selections_size

    assert_equal GraphQL::Field, v.nodes[3].class
    assert_nil v.nodes[3].alias
    assert_equal GraphQL::Name, v.nodes[3].name.class
    assert_equal 'field', v.nodes[3].name.value

    assert_equal GraphQL::Name, v.nodes[4].class
    assert_equal 'field', v.nodes[4].value
  end
end
