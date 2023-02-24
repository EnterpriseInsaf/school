#ifndef RPN_H
#define RPN_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct StrStack {
    char* substring;
    struct StrStack* next;
} StrStack;

typedef struct NumStack {
    double data;
    struct NumStack* next;
} NumStack;

StrStack* createNode(char* substring);
int is_digit(char ch);
int isEmpty(StrStack* root);
void push(StrStack** root, char* substring);
char* pop(StrStack** root);
char* peek(StrStack* root);
void display(StrStack* root);
int is_bracket(char a);
int is_sqrt(char* arr, int z);
int is_len_three(char* arr, int z);
int is_operator(char* arr, int z);
int isleft_bracket(char* arr);
int is_unary(char* arr);
int isleft_associative(char* arr);
int is_variable(char* arr, int z, char* variable);
int check_precedence(char* arr);
int compare_precedence(char* a, char* b);
StrStack* infix_to_postfix(char* arr, char choice, char* variable, char* result);
StrStack* reverse(StrStack* stack_output);
NumStack* createNumNode(double data);
int isnumEmpty(NumStack* root);
void push_num(NumStack** root, double data);
double pop_num(NumStack** root);
double peek_num(NumStack* root);
double token_to_double(char* token);
void unary_operator(char* token, NumStack* numstack);
double operate_rpn(StrStack* output);
int check_balance(char* arr);
void empty_input_buffer();
char user_choice();
char* user_input();
char* input_instructions();
char* check_input(char* arr);
double calculator(char* arr, char choice, char* variable, char* result);
char* int_to_string(int num);
char* double_to_string(double num);
int check_variable(char* variable);
char* check_def(char* variable);
char* variable_name(char* variable);
char* value_variable(char* variable);
double second_mode(char* variable, char* formula);

#endif