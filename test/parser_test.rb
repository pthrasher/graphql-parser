require_relative 'test_helper'

class ParserTest < Minitest::Test

  # example fragments borrowed from https://github.com/graphql/libgraphqlparser/blob/master/test/ParserTests.cpp

  def test_that_parsing_returns_an_ast
    expect_parse_success('{ field }')
    expect_parse_success('{ field(complex: { a: { b: [ $var ] } }) }')
  end

  def test_parse_error
    expect_parse_error('{')
    expect_parse_error('query myquery on type { field }')
    expect_parse_error('query myquery { field };')
    expect_parse_error("{ ...MissingOn }\nfragment MissingOn Type")
    expect_parse_error('{ field: {} }')
    expect_parse_error('notanoperation Foo { field }')
    expect_parse_error('...')
    expect_parse_error('query Foo($x: Complex = {a:{b:[ $var ] } }) { field }')
    expect_parse_error('fragment on on on { on }')
    expect_parse_error('{ ...on }')
    expect_parse_error('{ fieldWithNullableStringInput(input: null) }')
  end

  private

  def expect_parse_error(input)
    assert_raises(GraphQL::ParseError) do
      GraphQL::Parser.parse(input)
    end
  end

  def expect_parse_success(input)
    assert_equal GraphQL::AST, GraphQL::Parser.parse(input).class
  end
end
