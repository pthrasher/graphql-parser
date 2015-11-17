/**
 * Copyright (c) 2015, Facebook, Inc.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. An additional grant
 * of patent rights can be found in the PATENTS file in the same directory.
 */
/** @generated */

#include "c/GraphQLParser.h"
#include "c/GraphQLAstNode.h"
#include "c/GraphQLAstVisitor.h"
#include "c/GraphQLAst.h"

#include <ruby.h>

#include "graphql_ruby.h"

VALUE ast_class, parse_error, skip_children;

static struct GraphQLAstVisitorCallbacks cbs;

static void free_ast(void *x) {
  graphql_node_free((struct GraphQLAstNode*)x);
}

static const rb_data_type_t ast_type = { "AST", {0, free_ast,}, };

static VALUE INT2BOOL(int x) {
  return x ? Qtrue : Qfalse;
}


const rb_data_type_t definition_type = { "GraphQLAstDefinition", {}, };
VALUE definition_class;

const rb_data_type_t document_type = { "GraphQLAstDocument", {}, };
VALUE document_class;
ID visit_document_id;
ID end_visit_document_id;
static int visit_document(const struct GraphQLAstDocument *document, void *user_data) {
  VALUE parent = (VALUE)user_data;
  VALUE param = TypedData_Wrap_Struct(document_class, &document_type, (void*)document);
  return rb_funcall(parent, visit_document_id, 1, param) != skip_children;
}

static void end_visit_document(const struct GraphQLAstDocument *document, void *user_data) {
  VALUE parent = (VALUE)user_data;
  VALUE param = TypedData_Wrap_Struct(document_class, &document_type, (void*)document);
  rb_funcall(parent, end_visit_document_id, 1, param);
}

static VALUE document_get_definitions_size(VALUE self) {
  struct GraphQLAstDocument *node;
  TypedData_Get_Struct(self, struct GraphQLAstDocument, &document_type, node);
  return INT2FIX(GraphQLAstDocument_get_definitions_size(node));
}


const rb_data_type_t operation_definition_type = { "GraphQLAstOperationDefinition", {}, };
VALUE operation_definition_class;
ID visit_operation_definition_id;
ID end_visit_operation_definition_id;
static int visit_operation_definition(const struct GraphQLAstOperationDefinition *operation_definition, void *user_data) {
  VALUE parent = (VALUE)user_data;
  VALUE param = TypedData_Wrap_Struct(operation_definition_class, &operation_definition_type, (void*)operation_definition);
  return rb_funcall(parent, visit_operation_definition_id, 1, param) != skip_children;
}

static void end_visit_operation_definition(const struct GraphQLAstOperationDefinition *operation_definition, void *user_data) {
  VALUE parent = (VALUE)user_data;
  VALUE param = TypedData_Wrap_Struct(operation_definition_class, &operation_definition_type, (void*)operation_definition);
  rb_funcall(parent, end_visit_operation_definition_id, 1, param);
}

static VALUE operation_definition_get_operation(VALUE self) {
  struct GraphQLAstOperationDefinition *node;
  TypedData_Get_Struct(self, struct GraphQLAstOperationDefinition, &operation_definition_type, node);
  return rb_str_new_cstr(GraphQLAstOperationDefinition_get_operation(node));
}

static VALUE operation_definition_get_name(VALUE self) {
  struct GraphQLAstOperationDefinition *node;
  TypedData_Get_Struct(self, struct GraphQLAstOperationDefinition, &operation_definition_type, node);
  if (GraphQLAstOperationDefinition_get_name(node) == NULL) return Qnil;
  return TypedData_Wrap_Struct(name_class, &name_type, (void*)GraphQLAstOperationDefinition_get_name(node));
}

static VALUE operation_definition_get_variable_definitions_size(VALUE self) {
  struct GraphQLAstOperationDefinition *node;
  TypedData_Get_Struct(self, struct GraphQLAstOperationDefinition, &operation_definition_type, node);
  return INT2FIX(GraphQLAstOperationDefinition_get_variable_definitions_size(node));
}

static VALUE operation_definition_get_directives_size(VALUE self) {
  struct GraphQLAstOperationDefinition *node;
  TypedData_Get_Struct(self, struct GraphQLAstOperationDefinition, &operation_definition_type, node);
  return INT2FIX(GraphQLAstOperationDefinition_get_directives_size(node));
}

static VALUE operation_definition_get_selection_set(VALUE self) {
  struct GraphQLAstOperationDefinition *node;
  TypedData_Get_Struct(self, struct GraphQLAstOperationDefinition, &operation_definition_type, node);
  return TypedData_Wrap_Struct(selection_set_class, &selection_set_type, (void*)GraphQLAstOperationDefinition_get_selection_set(node));
}


const rb_data_type_t variable_definition_type = { "GraphQLAstVariableDefinition", {}, };
VALUE variable_definition_class;
ID visit_variable_definition_id;
ID end_visit_variable_definition_id;
static int visit_variable_definition(const struct GraphQLAstVariableDefinition *variable_definition, void *user_data) {
  VALUE parent = (VALUE)user_data;
  VALUE param = TypedData_Wrap_Struct(variable_definition_class, &variable_definition_type, (void*)variable_definition);
  return rb_funcall(parent, visit_variable_definition_id, 1, param) != skip_children;
}

static void end_visit_variable_definition(const struct GraphQLAstVariableDefinition *variable_definition, void *user_data) {
  VALUE parent = (VALUE)user_data;
  VALUE param = TypedData_Wrap_Struct(variable_definition_class, &variable_definition_type, (void*)variable_definition);
  rb_funcall(parent, end_visit_variable_definition_id, 1, param);
}

static VALUE variable_definition_get_variable(VALUE self) {
  struct GraphQLAstVariableDefinition *node;
  TypedData_Get_Struct(self, struct GraphQLAstVariableDefinition, &variable_definition_type, node);
  return TypedData_Wrap_Struct(variable_class, &variable_type, (void*)GraphQLAstVariableDefinition_get_variable(node));
}

static VALUE variable_definition_get_type(VALUE self) {
  struct GraphQLAstVariableDefinition *node;
  TypedData_Get_Struct(self, struct GraphQLAstVariableDefinition, &variable_definition_type, node);
  return TypedData_Wrap_Struct(type_class, &type_type, (void*)GraphQLAstVariableDefinition_get_type(node));
}

static VALUE variable_definition_get_default_value(VALUE self) {
  struct GraphQLAstVariableDefinition *node;
  TypedData_Get_Struct(self, struct GraphQLAstVariableDefinition, &variable_definition_type, node);
  if (GraphQLAstVariableDefinition_get_default_value(node) == NULL) return Qnil;
  return TypedData_Wrap_Struct(value_class, &value_type, (void*)GraphQLAstVariableDefinition_get_default_value(node));
}


const rb_data_type_t selection_set_type = { "GraphQLAstSelectionSet", {}, };
VALUE selection_set_class;
ID visit_selection_set_id;
ID end_visit_selection_set_id;
static int visit_selection_set(const struct GraphQLAstSelectionSet *selection_set, void *user_data) {
  VALUE parent = (VALUE)user_data;
  VALUE param = TypedData_Wrap_Struct(selection_set_class, &selection_set_type, (void*)selection_set);
  return rb_funcall(parent, visit_selection_set_id, 1, param) != skip_children;
}

static void end_visit_selection_set(const struct GraphQLAstSelectionSet *selection_set, void *user_data) {
  VALUE parent = (VALUE)user_data;
  VALUE param = TypedData_Wrap_Struct(selection_set_class, &selection_set_type, (void*)selection_set);
  rb_funcall(parent, end_visit_selection_set_id, 1, param);
}

static VALUE selection_set_get_selections_size(VALUE self) {
  struct GraphQLAstSelectionSet *node;
  TypedData_Get_Struct(self, struct GraphQLAstSelectionSet, &selection_set_type, node);
  return INT2FIX(GraphQLAstSelectionSet_get_selections_size(node));
}


const rb_data_type_t selection_type = { "GraphQLAstSelection", {}, };
VALUE selection_class;

const rb_data_type_t field_type = { "GraphQLAstField", {}, };
VALUE field_class;
ID visit_field_id;
ID end_visit_field_id;
static int visit_field(const struct GraphQLAstField *field, void *user_data) {
  VALUE parent = (VALUE)user_data;
  VALUE param = TypedData_Wrap_Struct(field_class, &field_type, (void*)field);
  return rb_funcall(parent, visit_field_id, 1, param) != skip_children;
}

static void end_visit_field(const struct GraphQLAstField *field, void *user_data) {
  VALUE parent = (VALUE)user_data;
  VALUE param = TypedData_Wrap_Struct(field_class, &field_type, (void*)field);
  rb_funcall(parent, end_visit_field_id, 1, param);
}

static VALUE field_get_alias(VALUE self) {
  struct GraphQLAstField *node;
  TypedData_Get_Struct(self, struct GraphQLAstField, &field_type, node);
  if (GraphQLAstField_get_alias(node) == NULL) return Qnil;
  return TypedData_Wrap_Struct(name_class, &name_type, (void*)GraphQLAstField_get_alias(node));
}

static VALUE field_get_name(VALUE self) {
  struct GraphQLAstField *node;
  TypedData_Get_Struct(self, struct GraphQLAstField, &field_type, node);
  return TypedData_Wrap_Struct(name_class, &name_type, (void*)GraphQLAstField_get_name(node));
}

static VALUE field_get_arguments_size(VALUE self) {
  struct GraphQLAstField *node;
  TypedData_Get_Struct(self, struct GraphQLAstField, &field_type, node);
  return INT2FIX(GraphQLAstField_get_arguments_size(node));
}

static VALUE field_get_directives_size(VALUE self) {
  struct GraphQLAstField *node;
  TypedData_Get_Struct(self, struct GraphQLAstField, &field_type, node);
  return INT2FIX(GraphQLAstField_get_directives_size(node));
}

static VALUE field_get_selection_set(VALUE self) {
  struct GraphQLAstField *node;
  TypedData_Get_Struct(self, struct GraphQLAstField, &field_type, node);
  if (GraphQLAstField_get_selection_set(node) == NULL) return Qnil;
  return TypedData_Wrap_Struct(selection_set_class, &selection_set_type, (void*)GraphQLAstField_get_selection_set(node));
}


const rb_data_type_t argument_type = { "GraphQLAstArgument", {}, };
VALUE argument_class;
ID visit_argument_id;
ID end_visit_argument_id;
static int visit_argument(const struct GraphQLAstArgument *argument, void *user_data) {
  VALUE parent = (VALUE)user_data;
  VALUE param = TypedData_Wrap_Struct(argument_class, &argument_type, (void*)argument);
  return rb_funcall(parent, visit_argument_id, 1, param) != skip_children;
}

static void end_visit_argument(const struct GraphQLAstArgument *argument, void *user_data) {
  VALUE parent = (VALUE)user_data;
  VALUE param = TypedData_Wrap_Struct(argument_class, &argument_type, (void*)argument);
  rb_funcall(parent, end_visit_argument_id, 1, param);
}

static VALUE argument_get_name(VALUE self) {
  struct GraphQLAstArgument *node;
  TypedData_Get_Struct(self, struct GraphQLAstArgument, &argument_type, node);
  return TypedData_Wrap_Struct(name_class, &name_type, (void*)GraphQLAstArgument_get_name(node));
}

static VALUE argument_get_value(VALUE self) {
  struct GraphQLAstArgument *node;
  TypedData_Get_Struct(self, struct GraphQLAstArgument, &argument_type, node);
  return TypedData_Wrap_Struct(value_class, &value_type, (void*)GraphQLAstArgument_get_value(node));
}


const rb_data_type_t fragment_spread_type = { "GraphQLAstFragmentSpread", {}, };
VALUE fragment_spread_class;
ID visit_fragment_spread_id;
ID end_visit_fragment_spread_id;
static int visit_fragment_spread(const struct GraphQLAstFragmentSpread *fragment_spread, void *user_data) {
  VALUE parent = (VALUE)user_data;
  VALUE param = TypedData_Wrap_Struct(fragment_spread_class, &fragment_spread_type, (void*)fragment_spread);
  return rb_funcall(parent, visit_fragment_spread_id, 1, param) != skip_children;
}

static void end_visit_fragment_spread(const struct GraphQLAstFragmentSpread *fragment_spread, void *user_data) {
  VALUE parent = (VALUE)user_data;
  VALUE param = TypedData_Wrap_Struct(fragment_spread_class, &fragment_spread_type, (void*)fragment_spread);
  rb_funcall(parent, end_visit_fragment_spread_id, 1, param);
}

static VALUE fragment_spread_get_name(VALUE self) {
  struct GraphQLAstFragmentSpread *node;
  TypedData_Get_Struct(self, struct GraphQLAstFragmentSpread, &fragment_spread_type, node);
  return TypedData_Wrap_Struct(name_class, &name_type, (void*)GraphQLAstFragmentSpread_get_name(node));
}

static VALUE fragment_spread_get_directives_size(VALUE self) {
  struct GraphQLAstFragmentSpread *node;
  TypedData_Get_Struct(self, struct GraphQLAstFragmentSpread, &fragment_spread_type, node);
  return INT2FIX(GraphQLAstFragmentSpread_get_directives_size(node));
}


const rb_data_type_t inline_fragment_type = { "GraphQLAstInlineFragment", {}, };
VALUE inline_fragment_class;
ID visit_inline_fragment_id;
ID end_visit_inline_fragment_id;
static int visit_inline_fragment(const struct GraphQLAstInlineFragment *inline_fragment, void *user_data) {
  VALUE parent = (VALUE)user_data;
  VALUE param = TypedData_Wrap_Struct(inline_fragment_class, &inline_fragment_type, (void*)inline_fragment);
  return rb_funcall(parent, visit_inline_fragment_id, 1, param) != skip_children;
}

static void end_visit_inline_fragment(const struct GraphQLAstInlineFragment *inline_fragment, void *user_data) {
  VALUE parent = (VALUE)user_data;
  VALUE param = TypedData_Wrap_Struct(inline_fragment_class, &inline_fragment_type, (void*)inline_fragment);
  rb_funcall(parent, end_visit_inline_fragment_id, 1, param);
}

static VALUE inline_fragment_get_type_condition(VALUE self) {
  struct GraphQLAstInlineFragment *node;
  TypedData_Get_Struct(self, struct GraphQLAstInlineFragment, &inline_fragment_type, node);
  return TypedData_Wrap_Struct(named_type_class, &named_type_type, (void*)GraphQLAstInlineFragment_get_type_condition(node));
}

static VALUE inline_fragment_get_directives_size(VALUE self) {
  struct GraphQLAstInlineFragment *node;
  TypedData_Get_Struct(self, struct GraphQLAstInlineFragment, &inline_fragment_type, node);
  return INT2FIX(GraphQLAstInlineFragment_get_directives_size(node));
}

static VALUE inline_fragment_get_selection_set(VALUE self) {
  struct GraphQLAstInlineFragment *node;
  TypedData_Get_Struct(self, struct GraphQLAstInlineFragment, &inline_fragment_type, node);
  return TypedData_Wrap_Struct(selection_set_class, &selection_set_type, (void*)GraphQLAstInlineFragment_get_selection_set(node));
}


const rb_data_type_t fragment_definition_type = { "GraphQLAstFragmentDefinition", {}, };
VALUE fragment_definition_class;
ID visit_fragment_definition_id;
ID end_visit_fragment_definition_id;
static int visit_fragment_definition(const struct GraphQLAstFragmentDefinition *fragment_definition, void *user_data) {
  VALUE parent = (VALUE)user_data;
  VALUE param = TypedData_Wrap_Struct(fragment_definition_class, &fragment_definition_type, (void*)fragment_definition);
  return rb_funcall(parent, visit_fragment_definition_id, 1, param) != skip_children;
}

static void end_visit_fragment_definition(const struct GraphQLAstFragmentDefinition *fragment_definition, void *user_data) {
  VALUE parent = (VALUE)user_data;
  VALUE param = TypedData_Wrap_Struct(fragment_definition_class, &fragment_definition_type, (void*)fragment_definition);
  rb_funcall(parent, end_visit_fragment_definition_id, 1, param);
}

static VALUE fragment_definition_get_name(VALUE self) {
  struct GraphQLAstFragmentDefinition *node;
  TypedData_Get_Struct(self, struct GraphQLAstFragmentDefinition, &fragment_definition_type, node);
  return TypedData_Wrap_Struct(name_class, &name_type, (void*)GraphQLAstFragmentDefinition_get_name(node));
}

static VALUE fragment_definition_get_type_condition(VALUE self) {
  struct GraphQLAstFragmentDefinition *node;
  TypedData_Get_Struct(self, struct GraphQLAstFragmentDefinition, &fragment_definition_type, node);
  return TypedData_Wrap_Struct(named_type_class, &named_type_type, (void*)GraphQLAstFragmentDefinition_get_type_condition(node));
}

static VALUE fragment_definition_get_directives_size(VALUE self) {
  struct GraphQLAstFragmentDefinition *node;
  TypedData_Get_Struct(self, struct GraphQLAstFragmentDefinition, &fragment_definition_type, node);
  return INT2FIX(GraphQLAstFragmentDefinition_get_directives_size(node));
}

static VALUE fragment_definition_get_selection_set(VALUE self) {
  struct GraphQLAstFragmentDefinition *node;
  TypedData_Get_Struct(self, struct GraphQLAstFragmentDefinition, &fragment_definition_type, node);
  return TypedData_Wrap_Struct(selection_set_class, &selection_set_type, (void*)GraphQLAstFragmentDefinition_get_selection_set(node));
}


const rb_data_type_t value_type = { "GraphQLAstValue", {}, };
VALUE value_class;

const rb_data_type_t variable_type = { "GraphQLAstVariable", {}, };
VALUE variable_class;
ID visit_variable_id;
ID end_visit_variable_id;
static int visit_variable(const struct GraphQLAstVariable *variable, void *user_data) {
  VALUE parent = (VALUE)user_data;
  VALUE param = TypedData_Wrap_Struct(variable_class, &variable_type, (void*)variable);
  return rb_funcall(parent, visit_variable_id, 1, param) != skip_children;
}

static void end_visit_variable(const struct GraphQLAstVariable *variable, void *user_data) {
  VALUE parent = (VALUE)user_data;
  VALUE param = TypedData_Wrap_Struct(variable_class, &variable_type, (void*)variable);
  rb_funcall(parent, end_visit_variable_id, 1, param);
}

static VALUE variable_get_name(VALUE self) {
  struct GraphQLAstVariable *node;
  TypedData_Get_Struct(self, struct GraphQLAstVariable, &variable_type, node);
  return TypedData_Wrap_Struct(name_class, &name_type, (void*)GraphQLAstVariable_get_name(node));
}


const rb_data_type_t int_value_type = { "GraphQLAstIntValue", {}, };
VALUE int_value_class;
ID visit_int_value_id;
ID end_visit_int_value_id;
static int visit_int_value(const struct GraphQLAstIntValue *int_value, void *user_data) {
  VALUE parent = (VALUE)user_data;
  VALUE param = TypedData_Wrap_Struct(int_value_class, &int_value_type, (void*)int_value);
  return rb_funcall(parent, visit_int_value_id, 1, param) != skip_children;
}

static void end_visit_int_value(const struct GraphQLAstIntValue *int_value, void *user_data) {
  VALUE parent = (VALUE)user_data;
  VALUE param = TypedData_Wrap_Struct(int_value_class, &int_value_type, (void*)int_value);
  rb_funcall(parent, end_visit_int_value_id, 1, param);
}

static VALUE int_value_get_value(VALUE self) {
  struct GraphQLAstIntValue *node;
  TypedData_Get_Struct(self, struct GraphQLAstIntValue, &int_value_type, node);
  return rb_str_new_cstr(GraphQLAstIntValue_get_value(node));
}


const rb_data_type_t float_value_type = { "GraphQLAstFloatValue", {}, };
VALUE float_value_class;
ID visit_float_value_id;
ID end_visit_float_value_id;
static int visit_float_value(const struct GraphQLAstFloatValue *float_value, void *user_data) {
  VALUE parent = (VALUE)user_data;
  VALUE param = TypedData_Wrap_Struct(float_value_class, &float_value_type, (void*)float_value);
  return rb_funcall(parent, visit_float_value_id, 1, param) != skip_children;
}

static void end_visit_float_value(const struct GraphQLAstFloatValue *float_value, void *user_data) {
  VALUE parent = (VALUE)user_data;
  VALUE param = TypedData_Wrap_Struct(float_value_class, &float_value_type, (void*)float_value);
  rb_funcall(parent, end_visit_float_value_id, 1, param);
}

static VALUE float_value_get_value(VALUE self) {
  struct GraphQLAstFloatValue *node;
  TypedData_Get_Struct(self, struct GraphQLAstFloatValue, &float_value_type, node);
  return rb_str_new_cstr(GraphQLAstFloatValue_get_value(node));
}


const rb_data_type_t string_value_type = { "GraphQLAstStringValue", {}, };
VALUE string_value_class;
ID visit_string_value_id;
ID end_visit_string_value_id;
static int visit_string_value(const struct GraphQLAstStringValue *string_value, void *user_data) {
  VALUE parent = (VALUE)user_data;
  VALUE param = TypedData_Wrap_Struct(string_value_class, &string_value_type, (void*)string_value);
  return rb_funcall(parent, visit_string_value_id, 1, param) != skip_children;
}

static void end_visit_string_value(const struct GraphQLAstStringValue *string_value, void *user_data) {
  VALUE parent = (VALUE)user_data;
  VALUE param = TypedData_Wrap_Struct(string_value_class, &string_value_type, (void*)string_value);
  rb_funcall(parent, end_visit_string_value_id, 1, param);
}

static VALUE string_value_get_value(VALUE self) {
  struct GraphQLAstStringValue *node;
  TypedData_Get_Struct(self, struct GraphQLAstStringValue, &string_value_type, node);
  return rb_str_new_cstr(GraphQLAstStringValue_get_value(node));
}


const rb_data_type_t boolean_value_type = { "GraphQLAstBooleanValue", {}, };
VALUE boolean_value_class;
ID visit_boolean_value_id;
ID end_visit_boolean_value_id;
static int visit_boolean_value(const struct GraphQLAstBooleanValue *boolean_value, void *user_data) {
  VALUE parent = (VALUE)user_data;
  VALUE param = TypedData_Wrap_Struct(boolean_value_class, &boolean_value_type, (void*)boolean_value);
  return rb_funcall(parent, visit_boolean_value_id, 1, param) != skip_children;
}

static void end_visit_boolean_value(const struct GraphQLAstBooleanValue *boolean_value, void *user_data) {
  VALUE parent = (VALUE)user_data;
  VALUE param = TypedData_Wrap_Struct(boolean_value_class, &boolean_value_type, (void*)boolean_value);
  rb_funcall(parent, end_visit_boolean_value_id, 1, param);
}

static VALUE boolean_value_get_value(VALUE self) {
  struct GraphQLAstBooleanValue *node;
  TypedData_Get_Struct(self, struct GraphQLAstBooleanValue, &boolean_value_type, node);
  return INT2BOOL(GraphQLAstBooleanValue_get_value(node));
}


const rb_data_type_t enum_value_type = { "GraphQLAstEnumValue", {}, };
VALUE enum_value_class;
ID visit_enum_value_id;
ID end_visit_enum_value_id;
static int visit_enum_value(const struct GraphQLAstEnumValue *enum_value, void *user_data) {
  VALUE parent = (VALUE)user_data;
  VALUE param = TypedData_Wrap_Struct(enum_value_class, &enum_value_type, (void*)enum_value);
  return rb_funcall(parent, visit_enum_value_id, 1, param) != skip_children;
}

static void end_visit_enum_value(const struct GraphQLAstEnumValue *enum_value, void *user_data) {
  VALUE parent = (VALUE)user_data;
  VALUE param = TypedData_Wrap_Struct(enum_value_class, &enum_value_type, (void*)enum_value);
  rb_funcall(parent, end_visit_enum_value_id, 1, param);
}

static VALUE enum_value_get_value(VALUE self) {
  struct GraphQLAstEnumValue *node;
  TypedData_Get_Struct(self, struct GraphQLAstEnumValue, &enum_value_type, node);
  return rb_str_new_cstr(GraphQLAstEnumValue_get_value(node));
}


const rb_data_type_t array_value_type = { "GraphQLAstArrayValue", {}, };
VALUE array_value_class;
ID visit_array_value_id;
ID end_visit_array_value_id;
static int visit_array_value(const struct GraphQLAstArrayValue *array_value, void *user_data) {
  VALUE parent = (VALUE)user_data;
  VALUE param = TypedData_Wrap_Struct(array_value_class, &array_value_type, (void*)array_value);
  return rb_funcall(parent, visit_array_value_id, 1, param) != skip_children;
}

static void end_visit_array_value(const struct GraphQLAstArrayValue *array_value, void *user_data) {
  VALUE parent = (VALUE)user_data;
  VALUE param = TypedData_Wrap_Struct(array_value_class, &array_value_type, (void*)array_value);
  rb_funcall(parent, end_visit_array_value_id, 1, param);
}

static VALUE array_value_get_values_size(VALUE self) {
  struct GraphQLAstArrayValue *node;
  TypedData_Get_Struct(self, struct GraphQLAstArrayValue, &array_value_type, node);
  return INT2FIX(GraphQLAstArrayValue_get_values_size(node));
}


const rb_data_type_t object_value_type = { "GraphQLAstObjectValue", {}, };
VALUE object_value_class;
ID visit_object_value_id;
ID end_visit_object_value_id;
static int visit_object_value(const struct GraphQLAstObjectValue *object_value, void *user_data) {
  VALUE parent = (VALUE)user_data;
  VALUE param = TypedData_Wrap_Struct(object_value_class, &object_value_type, (void*)object_value);
  return rb_funcall(parent, visit_object_value_id, 1, param) != skip_children;
}

static void end_visit_object_value(const struct GraphQLAstObjectValue *object_value, void *user_data) {
  VALUE parent = (VALUE)user_data;
  VALUE param = TypedData_Wrap_Struct(object_value_class, &object_value_type, (void*)object_value);
  rb_funcall(parent, end_visit_object_value_id, 1, param);
}

static VALUE object_value_get_fields_size(VALUE self) {
  struct GraphQLAstObjectValue *node;
  TypedData_Get_Struct(self, struct GraphQLAstObjectValue, &object_value_type, node);
  return INT2FIX(GraphQLAstObjectValue_get_fields_size(node));
}


const rb_data_type_t object_field_type = { "GraphQLAstObjectField", {}, };
VALUE object_field_class;
ID visit_object_field_id;
ID end_visit_object_field_id;
static int visit_object_field(const struct GraphQLAstObjectField *object_field, void *user_data) {
  VALUE parent = (VALUE)user_data;
  VALUE param = TypedData_Wrap_Struct(object_field_class, &object_field_type, (void*)object_field);
  return rb_funcall(parent, visit_object_field_id, 1, param) != skip_children;
}

static void end_visit_object_field(const struct GraphQLAstObjectField *object_field, void *user_data) {
  VALUE parent = (VALUE)user_data;
  VALUE param = TypedData_Wrap_Struct(object_field_class, &object_field_type, (void*)object_field);
  rb_funcall(parent, end_visit_object_field_id, 1, param);
}

static VALUE object_field_get_name(VALUE self) {
  struct GraphQLAstObjectField *node;
  TypedData_Get_Struct(self, struct GraphQLAstObjectField, &object_field_type, node);
  return TypedData_Wrap_Struct(name_class, &name_type, (void*)GraphQLAstObjectField_get_name(node));
}

static VALUE object_field_get_value(VALUE self) {
  struct GraphQLAstObjectField *node;
  TypedData_Get_Struct(self, struct GraphQLAstObjectField, &object_field_type, node);
  return TypedData_Wrap_Struct(value_class, &value_type, (void*)GraphQLAstObjectField_get_value(node));
}


const rb_data_type_t directive_type = { "GraphQLAstDirective", {}, };
VALUE directive_class;
ID visit_directive_id;
ID end_visit_directive_id;
static int visit_directive(const struct GraphQLAstDirective *directive, void *user_data) {
  VALUE parent = (VALUE)user_data;
  VALUE param = TypedData_Wrap_Struct(directive_class, &directive_type, (void*)directive);
  return rb_funcall(parent, visit_directive_id, 1, param) != skip_children;
}

static void end_visit_directive(const struct GraphQLAstDirective *directive, void *user_data) {
  VALUE parent = (VALUE)user_data;
  VALUE param = TypedData_Wrap_Struct(directive_class, &directive_type, (void*)directive);
  rb_funcall(parent, end_visit_directive_id, 1, param);
}

static VALUE directive_get_name(VALUE self) {
  struct GraphQLAstDirective *node;
  TypedData_Get_Struct(self, struct GraphQLAstDirective, &directive_type, node);
  return TypedData_Wrap_Struct(name_class, &name_type, (void*)GraphQLAstDirective_get_name(node));
}

static VALUE directive_get_arguments_size(VALUE self) {
  struct GraphQLAstDirective *node;
  TypedData_Get_Struct(self, struct GraphQLAstDirective, &directive_type, node);
  return INT2FIX(GraphQLAstDirective_get_arguments_size(node));
}


const rb_data_type_t type_type = { "GraphQLAstType", {}, };
VALUE type_class;

const rb_data_type_t named_type_type = { "GraphQLAstNamedType", {}, };
VALUE named_type_class;
ID visit_named_type_id;
ID end_visit_named_type_id;
static int visit_named_type(const struct GraphQLAstNamedType *named_type, void *user_data) {
  VALUE parent = (VALUE)user_data;
  VALUE param = TypedData_Wrap_Struct(named_type_class, &named_type_type, (void*)named_type);
  return rb_funcall(parent, visit_named_type_id, 1, param) != skip_children;
}

static void end_visit_named_type(const struct GraphQLAstNamedType *named_type, void *user_data) {
  VALUE parent = (VALUE)user_data;
  VALUE param = TypedData_Wrap_Struct(named_type_class, &named_type_type, (void*)named_type);
  rb_funcall(parent, end_visit_named_type_id, 1, param);
}

static VALUE named_type_get_name(VALUE self) {
  struct GraphQLAstNamedType *node;
  TypedData_Get_Struct(self, struct GraphQLAstNamedType, &named_type_type, node);
  return TypedData_Wrap_Struct(name_class, &name_type, (void*)GraphQLAstNamedType_get_name(node));
}


const rb_data_type_t list_type_type = { "GraphQLAstListType", {}, };
VALUE list_type_class;
ID visit_list_type_id;
ID end_visit_list_type_id;
static int visit_list_type(const struct GraphQLAstListType *list_type, void *user_data) {
  VALUE parent = (VALUE)user_data;
  VALUE param = TypedData_Wrap_Struct(list_type_class, &list_type_type, (void*)list_type);
  return rb_funcall(parent, visit_list_type_id, 1, param) != skip_children;
}

static void end_visit_list_type(const struct GraphQLAstListType *list_type, void *user_data) {
  VALUE parent = (VALUE)user_data;
  VALUE param = TypedData_Wrap_Struct(list_type_class, &list_type_type, (void*)list_type);
  rb_funcall(parent, end_visit_list_type_id, 1, param);
}

static VALUE list_type_get_type(VALUE self) {
  struct GraphQLAstListType *node;
  TypedData_Get_Struct(self, struct GraphQLAstListType, &list_type_type, node);
  return TypedData_Wrap_Struct(type_class, &type_type, (void*)GraphQLAstListType_get_type(node));
}


const rb_data_type_t non_null_type_type = { "GraphQLAstNonNullType", {}, };
VALUE non_null_type_class;
ID visit_non_null_type_id;
ID end_visit_non_null_type_id;
static int visit_non_null_type(const struct GraphQLAstNonNullType *non_null_type, void *user_data) {
  VALUE parent = (VALUE)user_data;
  VALUE param = TypedData_Wrap_Struct(non_null_type_class, &non_null_type_type, (void*)non_null_type);
  return rb_funcall(parent, visit_non_null_type_id, 1, param) != skip_children;
}

static void end_visit_non_null_type(const struct GraphQLAstNonNullType *non_null_type, void *user_data) {
  VALUE parent = (VALUE)user_data;
  VALUE param = TypedData_Wrap_Struct(non_null_type_class, &non_null_type_type, (void*)non_null_type);
  rb_funcall(parent, end_visit_non_null_type_id, 1, param);
}

static VALUE non_null_type_get_type(VALUE self) {
  struct GraphQLAstNonNullType *node;
  TypedData_Get_Struct(self, struct GraphQLAstNonNullType, &non_null_type_type, node);
  return TypedData_Wrap_Struct(type_class, &type_type, (void*)GraphQLAstNonNullType_get_type(node));
}


const rb_data_type_t name_type = { "GraphQLAstName", {}, };
VALUE name_class;
ID visit_name_id;
ID end_visit_name_id;
static int visit_name(const struct GraphQLAstName *name, void *user_data) {
  VALUE parent = (VALUE)user_data;
  VALUE param = TypedData_Wrap_Struct(name_class, &name_type, (void*)name);
  return rb_funcall(parent, visit_name_id, 1, param) != skip_children;
}

static void end_visit_name(const struct GraphQLAstName *name, void *user_data) {
  VALUE parent = (VALUE)user_data;
  VALUE param = TypedData_Wrap_Struct(name_class, &name_type, (void*)name);
  rb_funcall(parent, end_visit_name_id, 1, param);
}

static VALUE name_get_value(VALUE self) {
  struct GraphQLAstName *node;
  TypedData_Get_Struct(self, struct GraphQLAstName, &name_type, node);
  return rb_str_new_cstr(GraphQLAstName_get_value(node));
}



static VALUE parse(VALUE self, VALUE text) {
  char *input;
  struct GraphQLAstNode *n;
  const char *error;

  input = StringValueCStr(text);

  n = graphql_parse_string(input, &error);

  if (n == NULL) {
      VALUE exc = rb_exc_new_cstr(parse_error, error);
      graphql_error_free(error);
      rb_exc_raise(exc);
      return Qnil;
  }

  return TypedData_Wrap_Struct(ast_class, &ast_type, n);
}

static VALUE accept(VALUE self, VALUE ast) {
  struct GraphQLAstNode *n;

  TypedData_Get_Struct(ast, struct GraphQLAstNode, &ast_type, n);

  graphql_node_visit(n, &cbs, (void*)self);

  return Qnil;
}

void init_graphql(void) {
  VALUE module, parser, visitor, node_class;

  module = rb_define_module("GraphQL");

  parser = rb_define_module_under(module, "Parser");
  rb_define_module_function(parser, "parse", parse, 1);

  visitor = rb_define_class_under(parser, "Visitor", rb_cObject);
  rb_define_method(visitor, "accept", accept, 1);

  parse_error = rb_define_class_under(parser, "ParseError", rb_eArgError);

  ast_class = rb_define_class_under(parser, "AST", rb_cObject);

  node_class = rb_define_class_under(parser, "Node", rb_cObject);

  skip_children = rb_class_new_instance(0, NULL, rb_cObject);
  rb_define_const(parser, "SKIP_CHILDREN", skip_children);


  document_class = rb_define_class_under(parser, "Document", node_class);
  operation_definition_class = rb_define_class_under(parser, "OperationDefinition", node_class);
  variable_definition_class = rb_define_class_under(parser, "VariableDefinition", node_class);
  selection_set_class = rb_define_class_under(parser, "SelectionSet", node_class);
  field_class = rb_define_class_under(parser, "Field", node_class);
  argument_class = rb_define_class_under(parser, "Argument", node_class);
  fragment_spread_class = rb_define_class_under(parser, "FragmentSpread", node_class);
  inline_fragment_class = rb_define_class_under(parser, "InlineFragment", node_class);
  fragment_definition_class = rb_define_class_under(parser, "FragmentDefinition", node_class);
  variable_class = rb_define_class_under(parser, "Variable", node_class);
  int_value_class = rb_define_class_under(parser, "IntValue", node_class);
  float_value_class = rb_define_class_under(parser, "FloatValue", node_class);
  string_value_class = rb_define_class_under(parser, "StringValue", node_class);
  boolean_value_class = rb_define_class_under(parser, "BooleanValue", node_class);
  enum_value_class = rb_define_class_under(parser, "EnumValue", node_class);
  array_value_class = rb_define_class_under(parser, "ArrayValue", node_class);
  object_value_class = rb_define_class_under(parser, "ObjectValue", node_class);
  object_field_class = rb_define_class_under(parser, "ObjectField", node_class);
  directive_class = rb_define_class_under(parser, "Directive", node_class);
  named_type_class = rb_define_class_under(parser, "NamedType", node_class);
  list_type_class = rb_define_class_under(parser, "ListType", node_class);
  non_null_type_class = rb_define_class_under(parser, "NonNullType", node_class);
  name_class = rb_define_class_under(parser, "Name", node_class);

  rb_define_method(document_class, "definitions_size", document_get_definitions_size, 0);
  rb_define_method(operation_definition_class, "operation", operation_definition_get_operation, 0);
  rb_define_method(operation_definition_class, "name", operation_definition_get_name, 0);
  rb_define_method(operation_definition_class, "variable_definitions_size", operation_definition_get_variable_definitions_size, 0);
  rb_define_method(operation_definition_class, "directives_size", operation_definition_get_directives_size, 0);
  rb_define_method(operation_definition_class, "selection_set", operation_definition_get_selection_set, 0);
  rb_define_method(variable_definition_class, "variable", variable_definition_get_variable, 0);
  rb_define_method(variable_definition_class, "type", variable_definition_get_type, 0);
  rb_define_method(variable_definition_class, "default_value", variable_definition_get_default_value, 0);
  rb_define_method(selection_set_class, "selections_size", selection_set_get_selections_size, 0);
  rb_define_method(field_class, "alias", field_get_alias, 0);
  rb_define_method(field_class, "name", field_get_name, 0);
  rb_define_method(field_class, "arguments_size", field_get_arguments_size, 0);
  rb_define_method(field_class, "directives_size", field_get_directives_size, 0);
  rb_define_method(field_class, "selection_set", field_get_selection_set, 0);
  rb_define_method(argument_class, "name", argument_get_name, 0);
  rb_define_method(argument_class, "value", argument_get_value, 0);
  rb_define_method(fragment_spread_class, "name", fragment_spread_get_name, 0);
  rb_define_method(fragment_spread_class, "directives_size", fragment_spread_get_directives_size, 0);
  rb_define_method(inline_fragment_class, "type_condition", inline_fragment_get_type_condition, 0);
  rb_define_method(inline_fragment_class, "directives_size", inline_fragment_get_directives_size, 0);
  rb_define_method(inline_fragment_class, "selection_set", inline_fragment_get_selection_set, 0);
  rb_define_method(fragment_definition_class, "name", fragment_definition_get_name, 0);
  rb_define_method(fragment_definition_class, "type_condition", fragment_definition_get_type_condition, 0);
  rb_define_method(fragment_definition_class, "directives_size", fragment_definition_get_directives_size, 0);
  rb_define_method(fragment_definition_class, "selection_set", fragment_definition_get_selection_set, 0);
  rb_define_method(variable_class, "name", variable_get_name, 0);
  rb_define_method(int_value_class, "value", int_value_get_value, 0);
  rb_define_method(float_value_class, "value", float_value_get_value, 0);
  rb_define_method(string_value_class, "value", string_value_get_value, 0);
  rb_define_method(boolean_value_class, "value", boolean_value_get_value, 0);
  rb_define_method(enum_value_class, "value", enum_value_get_value, 0);
  rb_define_method(array_value_class, "values_size", array_value_get_values_size, 0);
  rb_define_method(object_value_class, "fields_size", object_value_get_fields_size, 0);
  rb_define_method(object_field_class, "name", object_field_get_name, 0);
  rb_define_method(object_field_class, "value", object_field_get_value, 0);
  rb_define_method(directive_class, "name", directive_get_name, 0);
  rb_define_method(directive_class, "arguments_size", directive_get_arguments_size, 0);
  rb_define_method(named_type_class, "name", named_type_get_name, 0);
  rb_define_method(list_type_class, "type", list_type_get_type, 0);
  rb_define_method(non_null_type_class, "type", non_null_type_get_type, 0);
  rb_define_method(name_class, "value", name_get_value, 0);

  visit_document_id = rb_intern("visit_document");
  end_visit_document_id = rb_intern("end_visit_document");
  visit_operation_definition_id = rb_intern("visit_operation_definition");
  end_visit_operation_definition_id = rb_intern("end_visit_operation_definition");
  visit_variable_definition_id = rb_intern("visit_variable_definition");
  end_visit_variable_definition_id = rb_intern("end_visit_variable_definition");
  visit_selection_set_id = rb_intern("visit_selection_set");
  end_visit_selection_set_id = rb_intern("end_visit_selection_set");
  visit_field_id = rb_intern("visit_field");
  end_visit_field_id = rb_intern("end_visit_field");
  visit_argument_id = rb_intern("visit_argument");
  end_visit_argument_id = rb_intern("end_visit_argument");
  visit_fragment_spread_id = rb_intern("visit_fragment_spread");
  end_visit_fragment_spread_id = rb_intern("end_visit_fragment_spread");
  visit_inline_fragment_id = rb_intern("visit_inline_fragment");
  end_visit_inline_fragment_id = rb_intern("end_visit_inline_fragment");
  visit_fragment_definition_id = rb_intern("visit_fragment_definition");
  end_visit_fragment_definition_id = rb_intern("end_visit_fragment_definition");
  visit_variable_id = rb_intern("visit_variable");
  end_visit_variable_id = rb_intern("end_visit_variable");
  visit_int_value_id = rb_intern("visit_int_value");
  end_visit_int_value_id = rb_intern("end_visit_int_value");
  visit_float_value_id = rb_intern("visit_float_value");
  end_visit_float_value_id = rb_intern("end_visit_float_value");
  visit_string_value_id = rb_intern("visit_string_value");
  end_visit_string_value_id = rb_intern("end_visit_string_value");
  visit_boolean_value_id = rb_intern("visit_boolean_value");
  end_visit_boolean_value_id = rb_intern("end_visit_boolean_value");
  visit_enum_value_id = rb_intern("visit_enum_value");
  end_visit_enum_value_id = rb_intern("end_visit_enum_value");
  visit_array_value_id = rb_intern("visit_array_value");
  end_visit_array_value_id = rb_intern("end_visit_array_value");
  visit_object_value_id = rb_intern("visit_object_value");
  end_visit_object_value_id = rb_intern("end_visit_object_value");
  visit_object_field_id = rb_intern("visit_object_field");
  end_visit_object_field_id = rb_intern("end_visit_object_field");
  visit_directive_id = rb_intern("visit_directive");
  end_visit_directive_id = rb_intern("end_visit_directive");
  visit_named_type_id = rb_intern("visit_named_type");
  end_visit_named_type_id = rb_intern("end_visit_named_type");
  visit_list_type_id = rb_intern("visit_list_type");
  end_visit_list_type_id = rb_intern("end_visit_list_type");
  visit_non_null_type_id = rb_intern("visit_non_null_type");
  end_visit_non_null_type_id = rb_intern("end_visit_non_null_type");
  visit_name_id = rb_intern("visit_name");
  end_visit_name_id = rb_intern("end_visit_name");

  cbs.visit_document = visit_document;
  cbs.end_visit_document = end_visit_document;
  cbs.visit_operation_definition = visit_operation_definition;
  cbs.end_visit_operation_definition = end_visit_operation_definition;
  cbs.visit_variable_definition = visit_variable_definition;
  cbs.end_visit_variable_definition = end_visit_variable_definition;
  cbs.visit_selection_set = visit_selection_set;
  cbs.end_visit_selection_set = end_visit_selection_set;
  cbs.visit_field = visit_field;
  cbs.end_visit_field = end_visit_field;
  cbs.visit_argument = visit_argument;
  cbs.end_visit_argument = end_visit_argument;
  cbs.visit_fragment_spread = visit_fragment_spread;
  cbs.end_visit_fragment_spread = end_visit_fragment_spread;
  cbs.visit_inline_fragment = visit_inline_fragment;
  cbs.end_visit_inline_fragment = end_visit_inline_fragment;
  cbs.visit_fragment_definition = visit_fragment_definition;
  cbs.end_visit_fragment_definition = end_visit_fragment_definition;
  cbs.visit_variable = visit_variable;
  cbs.end_visit_variable = end_visit_variable;
  cbs.visit_int_value = visit_int_value;
  cbs.end_visit_int_value = end_visit_int_value;
  cbs.visit_float_value = visit_float_value;
  cbs.end_visit_float_value = end_visit_float_value;
  cbs.visit_string_value = visit_string_value;
  cbs.end_visit_string_value = end_visit_string_value;
  cbs.visit_boolean_value = visit_boolean_value;
  cbs.end_visit_boolean_value = end_visit_boolean_value;
  cbs.visit_enum_value = visit_enum_value;
  cbs.end_visit_enum_value = end_visit_enum_value;
  cbs.visit_array_value = visit_array_value;
  cbs.end_visit_array_value = end_visit_array_value;
  cbs.visit_object_value = visit_object_value;
  cbs.end_visit_object_value = end_visit_object_value;
  cbs.visit_object_field = visit_object_field;
  cbs.end_visit_object_field = end_visit_object_field;
  cbs.visit_directive = visit_directive;
  cbs.end_visit_directive = end_visit_directive;
  cbs.visit_named_type = visit_named_type;
  cbs.end_visit_named_type = end_visit_named_type;
  cbs.visit_list_type = visit_list_type;
  cbs.end_visit_list_type = end_visit_list_type;
  cbs.visit_non_null_type = visit_non_null_type;
  cbs.end_visit_non_null_type = end_visit_non_null_type;
  cbs.visit_name = visit_name;
  cbs.end_visit_name = end_visit_name;

}
