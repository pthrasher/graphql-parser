require 'mkmf'

dir_config('graphql', '/usr/local/include/GraphQL', '/usr/local/lib')

abort 'missing libgraphqlparser' unless have_library 'graphqlparser'

create_makefile 'graphql_parser/graphql_parser'
