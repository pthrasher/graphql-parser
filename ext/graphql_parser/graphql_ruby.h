/**
 * Copyright (c) 2015, Facebook, Inc.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. An additional grant
 * of patent rights can be found in the PATENTS file in the same directory.
 */
/** @generated */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <ruby.h>

void init_graphql(void);


struct GraphQLAstDefinition;
extern const rb_data_type_t definition_type;
extern VALUE definition_class;

struct GraphQLAstDocument;
extern const rb_data_type_t document_type;
extern VALUE document_class;
extern ID visit_document_id;
extern ID end_visit_document_id;

struct GraphQLAstOperationDefinition;
extern const rb_data_type_t operation_definition_type;
extern VALUE operation_definition_class;
extern ID visit_operation_definition_id;
extern ID end_visit_operation_definition_id;

struct GraphQLAstVariableDefinition;
extern const rb_data_type_t variable_definition_type;
extern VALUE variable_definition_class;
extern ID visit_variable_definition_id;
extern ID end_visit_variable_definition_id;

struct GraphQLAstSelectionSet;
extern const rb_data_type_t selection_set_type;
extern VALUE selection_set_class;
extern ID visit_selection_set_id;
extern ID end_visit_selection_set_id;

struct GraphQLAstSelection;
extern const rb_data_type_t selection_type;
extern VALUE selection_class;

struct GraphQLAstField;
extern const rb_data_type_t field_type;
extern VALUE field_class;
extern ID visit_field_id;
extern ID end_visit_field_id;

struct GraphQLAstArgument;
extern const rb_data_type_t argument_type;
extern VALUE argument_class;
extern ID visit_argument_id;
extern ID end_visit_argument_id;

struct GraphQLAstFragmentSpread;
extern const rb_data_type_t fragment_spread_type;
extern VALUE fragment_spread_class;
extern ID visit_fragment_spread_id;
extern ID end_visit_fragment_spread_id;

struct GraphQLAstInlineFragment;
extern const rb_data_type_t inline_fragment_type;
extern VALUE inline_fragment_class;
extern ID visit_inline_fragment_id;
extern ID end_visit_inline_fragment_id;

struct GraphQLAstFragmentDefinition;
extern const rb_data_type_t fragment_definition_type;
extern VALUE fragment_definition_class;
extern ID visit_fragment_definition_id;
extern ID end_visit_fragment_definition_id;

struct GraphQLAstValue;
extern const rb_data_type_t value_type;
extern VALUE value_class;

struct GraphQLAstVariable;
extern const rb_data_type_t variable_type;
extern VALUE variable_class;
extern ID visit_variable_id;
extern ID end_visit_variable_id;

struct GraphQLAstIntValue;
extern const rb_data_type_t int_value_type;
extern VALUE int_value_class;
extern ID visit_int_value_id;
extern ID end_visit_int_value_id;

struct GraphQLAstFloatValue;
extern const rb_data_type_t float_value_type;
extern VALUE float_value_class;
extern ID visit_float_value_id;
extern ID end_visit_float_value_id;

struct GraphQLAstStringValue;
extern const rb_data_type_t string_value_type;
extern VALUE string_value_class;
extern ID visit_string_value_id;
extern ID end_visit_string_value_id;

struct GraphQLAstBooleanValue;
extern const rb_data_type_t boolean_value_type;
extern VALUE boolean_value_class;
extern ID visit_boolean_value_id;
extern ID end_visit_boolean_value_id;

struct GraphQLAstEnumValue;
extern const rb_data_type_t enum_value_type;
extern VALUE enum_value_class;
extern ID visit_enum_value_id;
extern ID end_visit_enum_value_id;

struct GraphQLAstArrayValue;
extern const rb_data_type_t array_value_type;
extern VALUE array_value_class;
extern ID visit_array_value_id;
extern ID end_visit_array_value_id;

struct GraphQLAstObjectValue;
extern const rb_data_type_t object_value_type;
extern VALUE object_value_class;
extern ID visit_object_value_id;
extern ID end_visit_object_value_id;

struct GraphQLAstObjectField;
extern const rb_data_type_t object_field_type;
extern VALUE object_field_class;
extern ID visit_object_field_id;
extern ID end_visit_object_field_id;

struct GraphQLAstDirective;
extern const rb_data_type_t directive_type;
extern VALUE directive_class;
extern ID visit_directive_id;
extern ID end_visit_directive_id;

struct GraphQLAstType;
extern const rb_data_type_t type_type;
extern VALUE type_class;

struct GraphQLAstNamedType;
extern const rb_data_type_t named_type_type;
extern VALUE named_type_class;
extern ID visit_named_type_id;
extern ID end_visit_named_type_id;

struct GraphQLAstListType;
extern const rb_data_type_t list_type_type;
extern VALUE list_type_class;
extern ID visit_list_type_id;
extern ID end_visit_list_type_id;

struct GraphQLAstNonNullType;
extern const rb_data_type_t non_null_type_type;
extern VALUE non_null_type_class;
extern ID visit_non_null_type_id;
extern ID end_visit_non_null_type_id;

struct GraphQLAstName;
extern const rb_data_type_t name_type;
extern VALUE name_class;
extern ID visit_name_id;
extern ID end_visit_name_id;



#ifdef __cplusplus
}
#endif

