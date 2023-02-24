#include <stdio.h>
#include <stdlib.h>

int sub_input();
void stat_array();
int output();

int main(){
    int sub = sub_input();
    printf("%d", sub);

    return 0;
}

int sub_input(){
    int sub;
    if(scanf("%d", &sub) == 1 && sub < 5 && sub > 0){
        return sub;
    }
    else{
        return 1;
    }
}
