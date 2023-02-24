#include <stdio.h>

int sum(int a, int b);

int main()
{
    int a;
    int b;
    if(scanf("%d", &a) != 1){
        printf("n/a");
    }
    if(scanf("%d", &b) != 1){
        printf("n/a");
    }

    sum(a, b);

    return 0;
}

int sum(int a, int b){
    int plus = (a + b);
    int minus = (a - b);
    int mult = (a * b);
    if(b == 0){
        printf("%d %d %d n/a", plus, minus, mult);
    }else{
        int del = (a / b);
        printf("%d %d %d %d", plus, minus, mult, del);
    }

    return 0;
}
