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

static VALUE ast_class;

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

    return TypedData_Wrap_Struct(ast_class, &ast_type, n);
}

static VALUE
accept(int argc, VALUE *argv, VALUE obj) {
    struct GraphQLAstNode *n;

    if (argc != 1) {
        rb_raise(rb_eArgError, "Takes 1 argument");
    }

    TypedData_Get_Struct(argv[0], struct GraphQLAstNode, &ast_type, n);

    graphql_node_visit(n, &cbs, &obj);

    return Qnil;
}

void
Init_graphql_parser(void) {
    VALUE module, parser, visitor;

    module = rb_define_module("GraphQL");

    parser = rb_define_module_under(module, "Parser");
    rb_define_module_function(parser, "parse", parse, -1);

    visitor = rb_define_class_under(module, "Visitor", rb_cObject);
    rb_define_method(visitor, "accept", accept, -1);

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
