#include <stdio.h>


int main(){
    int* pc, c;
    c = 5;
    pc = &c;

    printf("%d\n", pc);
    printf("%d\n", &c);
    printf("%d\n", c);
    printf("%d\n", *pc);
    printf("%d\n", &pc);



    return 0;
}
