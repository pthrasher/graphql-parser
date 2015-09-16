require 'mkmf'

ROOT = '../../../..'

`cd #{ROOT}/libgraphqlparser && cmake . && make && cd -`

dir_config('graphql', "#{ROOT}/libgraphqlparser", "#{ROOT}/libgraphqlparser")

AST = "#{ROOT}/libgraphqlparser/ast"
`PYTHONPATH=$PYTHONPATH:#{ROOT}/generators python #{AST}/ast.py ruby_header_gen #{AST}/ast.ast > #{ROOT}/ext/graphql_parser/graphql_ruby.h`
`PYTHONPATH=$PYTHONPATH:#{ROOT}/generators python #{AST}/ast.py ruby_impl_gen #{AST}/ast.ast > #{ROOT}/ext/graphql_parser/graphql_ruby.c`

abort 'missing libgraphqlparser' unless have_library 'graphqlparser'

create_makefile 'graphql_parser'
