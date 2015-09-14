#include <ruby.h>

#include "GraphQLParser.h"
#include "GraphQLASTNode.h"

VALUE parse() {
    struct GraphQLAstNode *n;

    n = graphql_parse_string("", NULL);

    if (n == NULL) {
        return Qnil;
    }
    graphql_node_free(n);

    return rb_cObject;
}

void
Init_graphql_parser(void) {
    VALUE m, c;

    m = rb_define_module("GraphQL");
    c = rb_define_class_under(m, "Parser", rb_cObject);
    rb_define_method(c, "parse", parse, 0);
}
