#include <ruby.h>

#include "c/GraphQLParser.h"
#include "c/GraphQLAstNode.h"
#include "c/GraphQLAstVisitor.h"

#define GENERATE_SYMBOLS(type, snake_type) \
    static ID visit_##snake_type##_sym; \
    static ID end_visit_##snake_type##_sym;
FOR_EACH_CONCRETE_TYPE(GENERATE_SYMBOLS)

#define GENERATE_VISIT_CB(type, snake_type) \
    static int visit_##snake_type(const struct GraphQLAst##type *snake_type, \
            void *user_data) { \
        VALUE parent = (VALUE)user_data; \
        return FIXNUM_P(rb_funcall(parent, visit_##snake_type##_sym, 0)); \
    }
FOR_EACH_CONCRETE_TYPE(GENERATE_VISIT_CB)

#define GENERATE_END_VISIT_CB(type, snake_type) \
    static void end_visit_##snake_type(const struct GraphQLAst##type *snake_type, \
            void *user_data) { \
        VALUE parent = (VALUE)user_data; \
        rb_funcall(parent, end_visit_##snake_type##_sym, 0); \
    }
FOR_EACH_CONCRETE_TYPE(GENERATE_END_VISIT_CB)

static struct GraphQLAstVisitorCallbacks cbs;

static VALUE ast_class, parse_error;

static void
free_ast(void *x) {
    graphql_node_free((struct GraphQLAstNode*)x);
}

static const rb_data_type_t ast_type = {
    "AST",
    {0, free_ast,},
    0, 0,
};

static VALUE
parse(VALUE self, VALUE text) {
    char *input;
    struct GraphQLAstNode *n;
    const char *error;

    input = StringValueCStr(text);

    n = graphql_parse_string(input, &error);

    if (n == NULL) {
        rb_raise(parse_error, "%s", error);
        graphql_error_free(error);
        return Qnil;
    }

    return TypedData_Wrap_Struct(ast_class, &ast_type, n);
}

static VALUE
accept(VALUE self, VALUE ast) {
    struct GraphQLAstNode *n;

    TypedData_Get_Struct(ast, struct GraphQLAstNode, &ast_type, n);

    graphql_node_visit(n, &cbs, (void*)self);

    return Qnil;
}

void
Init_graphql_parser(void) {
    VALUE module, parser, visitor;

    module = rb_define_module("GraphQL");

    parser = rb_define_module_under(module, "Parser");
    rb_define_module_function(parser, "parse", parse, 1);

    visitor = rb_define_class_under(module, "Visitor", rb_cObject);
    rb_define_method(visitor, "accept", accept, 1);

    parse_error = rb_define_class_under(module, "ParseError", rb_eArgError);

    ast_class = rb_define_class_under(module, "AST", rb_cObject);

#define INTERN_SYMBOLS(type, snake_type) \
    visit_##snake_type##_sym = rb_intern("visit_" #snake_type); \
    end_visit_##snake_type##_sym = rb_intern("end_visit_" #snake_type);

FOR_EACH_CONCRETE_TYPE(INTERN_SYMBOLS)

#define FILL_IN_CBS(type, snake_type) \
    cbs.visit_##snake_type = visit_##snake_type;   \
    cbs.end_visit_##snake_type = end_visit_##snake_type;

    FOR_EACH_CONCRETE_TYPE(FILL_IN_CBS)
}
