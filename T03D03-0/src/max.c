#include <stdio.h>

int max(int a, int b);

int main(){
    int a, b;
    if(scanf("%d", &a) != 1){
        printf("n/a");
    }
    if(scanf("%d", &b) != 1){
        printf("n/a");
    }

    max(a, b);

    return 0;
}

int max(int a, int b){
    int max;
    if(a > b){
        max = a;
    }else{
        max = b;
    }
    printf("%d", max);
    
    return 0;
}