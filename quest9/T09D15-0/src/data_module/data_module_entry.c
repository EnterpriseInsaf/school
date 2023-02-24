#include <stdio.h>
#include <stdlib.h>
#include "data_process.h"
#include "../data_libs/data_io.h"
#include "../data_libs/data_stat.h"

int main()
{
    int n;
    if(scanf("%d", &n) && n>1){
        double *data=malloc(n*sizeof(double));
        
        //Don`t forget to allocate memory !

        input(data, n);
        if (normalization(data, n)){
            output(data, n);
        }
        else{
            printf("ERROR");
        }
        free(data);
    }
    else{
        printf("ERROR");
    }
}
