#include <stdio.h>

//int sum(int a, int b);


void input(int* a, int* b){
    printf("Input 2 number: ");
    *a = scanf("%d", *a);
    *b = scanf("%d", *a);


}

int main(void)
{
    int a, b;
    input(&a, &b);
    printf("%d %d", a, b);
    //int b;
    //a = input();
    //printf("%d %d", a, b);
    //sum(t);


    return 0;
}

/*int sum(int a, int b){
    scanf("%d%d", &a);
    scanf("%d%d", &b);
    fflush(stdin);

    res1 = a + b;
    res2 = a - b;
    res3 = a * b;
    res4 = a / b;

    printf("%d %d %d %d", res1, res2, res3, res4);

    return 0;
}*/
