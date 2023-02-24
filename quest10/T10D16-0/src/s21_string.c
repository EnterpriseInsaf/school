#include <stdio.h>


int s21_strlen(char* str){
    int lenght = 0;

    while (*str++)
    {
        lenght++;
    }
    return lenght;
}

int s21_strcmp(char* str1, char* str2){
    while(*str1 && (*str1 == *str2)){
        str1++;
        str2++;
    }
    return *(unsigned char *) str1 - *(unsigned char *) str2;
}

void s21_strcpy(char* dest, char* src){
    char *start = dest;
    while ((*dest++ = *src++));
    return start; 

}
