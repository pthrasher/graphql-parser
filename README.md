# GraphQL::Parser

A small ruby gem wrapping the
[libgraphqlparser](https://github.com/graphql/libgraphqlparser) C library for
parsing [GraphQL](http://graphql.org/).

## Installation

Add this line to your application's Gemfile:

```ruby
gem 'graphql-parser'
```

And then execute:

    $ bundle

Or install it yourself as:

    $ gem install graphql-parser

## Usage

Parse your graphql string to get an AST:
```ruby
ast = GraphQL::Parser.parse('{ some_graphql_string }') # returns GraphQL::AST
```

This will raise `GraphQL::ParseError` on malformed input.

Implement a visitor:
```ruby
class MyVisitor < GraphQL::Visitor
  def visit_document(node)
    # do something interesting in pre-order
  end

  def end_visit_document(node)
    # do something interesting in post-order
  end

  # implement visit methods for all other GraphQL node types or define an
  # appropriate `method_missing` for ones you don't want to handle
end
```

And walk the AST:
```ruby
v = MyVisitor.new
v.accept(ast)
```

You can return `GraphQL::SKIP_CHILDREN` from a visitor to skip visiting that
node's children.

## Contributing

1. Fork it ( https://github.com/[my-github-username]/graphql-parser/fork )
2. Create your feature branch (`git checkout -b my-new-feature`)
3. Commit your changes (`git commit -am 'Add some feature'`)
4. Push to the branch (`git push origin my-new-feature`)
5. Create a new Pull Request
