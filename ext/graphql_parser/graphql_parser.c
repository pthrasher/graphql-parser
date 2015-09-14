#include <ruby.h>

#include "GraphQLParser.h"
#include "GraphQLASTNode.h"
#include "GraphQLASTVisitor.h"

#define GENERATE_SYMBOLS(type, snake_type) \
    static ID visit_##snake_type##_sym; \
    static ID end_visit_##snake_type##_sym;
FOR_EACH_CONCRETE_TYPE(GENERATE_SYMBOLS)

#define GENERATE_VISIT_CB(type, snake_type) \
    static int visit_##snake_type(const struct GraphQLAst##type *snake_type, \
            void *user_data) { \
        VALUE parent = *(VALUE*)user_data; \
        return FIXNUM_P(rb_funcall(parent, visit_##snake_type##_sym, 0)); \
    }
FOR_EACH_CONCRETE_TYPE(GENERATE_VISIT_CB)

#define GENERATE_END_VISIT_CB(type, snake_type) \
    static void end_visit_##snake_type(const struct GraphQLAst##type *snake_type, \
            void *user_data) { \
        VALUE parent = *(VALUE*)user_data; \
        rb_funcall(parent, end_visit_##snake_type##_sym, 0); \
    }
FOR_EACH_CONCRETE_TYPE(GENERATE_END_VISIT_CB)

static struct GraphQLAstVisitorCallbacks cbs;

static VALUE
parse(int argc, VALUE *argv, VALUE obj) {
    char *input;
    struct GraphQLAstNode *n;

    if (argc != 1) {
        rb_raise(rb_eArgError, "Takes 1 argument");
    }
    input = StringValueCStr(argv[0]);

    n = graphql_parse_string(input, NULL);

    if (n == NULL) {
        return Qnil;
    }

    graphql_node_visit(n, &cbs, &obj);

    graphql_node_free(n);
    return Qnil;
}

void
Init_graphql_parser(void) {
    VALUE m, c;

    m = rb_define_module("GraphQL");
    c = rb_define_class_under(m, "Parser", rb_cObject);
    rb_define_method(c, "parse", parse, -1);

#define INTERN_SYMBOLS(type, snake_type) \
    visit_##snake_type##_sym = rb_intern("visit_" #snake_type); \
    end_visit_##snake_type##_sym = rb_intern("end_visit" #snake_type);

FOR_EACH_CONCRETE_TYPE(INTERN_SYMBOLS)

#define FILL_IN_CBS(type, snake_type) \
    cbs.visit_##snake_type = visit_##snake_type;   \
    cbs.end_visit_##snake_type = end_visit_##snake_type;

    FOR_EACH_CONCRETE_TYPE(FILL_IN_CBS)
}
