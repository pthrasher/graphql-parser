#include <ruby.h>

#include "GraphQLAstNode.h"

void
Init_graphql_parser(void) {
    VALUE m, c;

    m = rb_define_module("GraphQL");
    c = rb_define_class_under(m, "Node", rb_cObject);
    c = rb_define_class_under(m, "Location", rb_cObject);
}
