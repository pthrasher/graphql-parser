require_relative 'test_helper'

class VisitorTest < Minitest::Test
  class Visitor < GraphQL::Visitor
    attr_accessor :nodes

    def initialize
      @nodes = []
    end

    def method_missing(name)
      @nodes << name
    end
  end

  def test_visiting_basic_query
    v = Visitor.new
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

  class SkipChildrenVisitor < Visitor
    def visit_document
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
end
