require 'mkmf'

ROOT = '../../../..'
dir_config('graphql', "#{ROOT}/libgraphqlparser", "#{ROOT}/libgraphqlparser")

SRC = "#{ROOT}/ext/graphql_parser/graphql_ruby"
unless File.exist?("#{SRC}.c") && File.exist?("#{SRC}.h")
  abort '''
  Missing the generated bindings. Please run `./script/setup` from
  the root of the repository to create them.
  '''
end

abort 'missing libgraphqlparser' unless have_library 'graphqlparser'

create_makefile 'graphql_parser'
