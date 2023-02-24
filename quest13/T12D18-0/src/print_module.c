#include <stdio.h>
#include <time.h>

#include "print_module.h"

int print_char(char ch) 
{
    return putchar(ch);
}

void print_log(char (*print) (char), char* message){
    int hours, minutes, seconds;
    time_t now;
    time(&now);
    struct tm *local = localtime(&now);

    hours = local->tm_hour;
    minutes = local->tm_min;
    seconds = local->tm_sec;
    
    printf("[LOG] %02d/%02d/%d\n", hours, minutes, seconds);
}
