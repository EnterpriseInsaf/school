#include <stdio.h>

int main(){
    float x, y;
    if(scanf("%f %f", &x, &y) != 1){
        printf("n/a");
    }else{
        float circle = pow(x, 2) + pow(y, 2);

        if(circle > 25){
            printf("MISS");
        }else{
            printf("GOTCHA");
            }
    }

    return 0;
}
