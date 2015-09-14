require_relative 'test_helper'

class VisitorTest < Minitest::Test
  class Visitor < GraphQL::Visitor
  end

  def setup
    @ast = GraphQL::Parser.parse('{ field }')
  end

  def test_that_parsing_returns_an_ast
    v = Visitor.new
    v.expects(:visit_document).once
    v.expects(:end_visit_document).once
    v.accept(@ast)
  end
end
