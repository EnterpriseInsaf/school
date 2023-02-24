#include <stdio.h>
#include <stdlib.h>

#include "s21_string.h"

void s21_strlen_test();
void s21_strcmp_test();
void s21_strcpy_test();

int main(){
    s21_strlen_test();
    s21_strcmp_test();
    s21_strcpy_test();

    return 0;
}

void s21_strlen_test(){
    char* str[][2] = {
        {"Hello", "5"},
        {"1234", "4"},
        {" ", "1"},
        {"\n", "2"}
    };

    for(int i = 0; i < 4; i++){
        int len = s21_strlen(str[i][0]);
        int exlen = atoi(str[i][1]);
        if(len == exlen){
            printf("\nINPUT %d OUTPUT %d SUCCESS", exlen, len);
        }else{
            printf("\nINPUT %d OUTPUT %d FAIL", exlen, len);
        }
    }
}

void s21_strcmp_test(){
    char* str1[][3] = {
        {"Hello", "Hello", "0"},
        {"1234", "123", "1"},
        {"123", "1234", "-1"}
    };

    char* str2[][3] = {
        {"Hello", "Hello", "0"},
        {"1234", "123", "1"},
        {"123", "1234", "-1"}
    };

    for(int i = 0; i < 3; i++){
        int len2 = s21_strcmp(str1[i][0], str2[i][0]);
        int exlen2 = atoi(str1[i][1]);
        if(len2 == exlen2){
            printf("\nINPUT %d OUTPUT %d SUCCESS", exlen2, len2);
        }else{
            printf("\nINPUT %d OUTPUT %d FAIL", exlen2, len2);
        }
    }

    for(int i = 0; i < 3; i++){
        int len3 = s21_strcmp(str2[i][0], str2[i][0]);
        int exlen3 = atoi(str2[i][1]);
        if(len3 == exlen3){
            printf("\nINPUT %d OUTPUT %d SUCCESS", exlen3, len3);
        }else{
            printf("\nINPUT %d OUTPUT %d FAIL", exlen3, len3);
        }
    }
}

void s21_strcpy_test(){
    const char* test_data[][2] = {
        {"hello", "hello"},
        {"world", "world"},
        {"", ""},
        {"abcdefghijklmnopqrstuvwxyz", "abcdefghijklmnopqrstuvwxyz"}
    };
    int i;
    char result[40];
    for (i = 0; i < 4; i++){
        s21_strcpy(result, test_data[i][0]);
        printf("Test %d Inputs %s Ouputs %s Expected %s Result %s\n", i+1, test_data[i][0], result, test_data[i][1], s21_strcmp(result, test_data[i][1] == 0 ? "SUCCESS" : "FAIL"));
    }
}