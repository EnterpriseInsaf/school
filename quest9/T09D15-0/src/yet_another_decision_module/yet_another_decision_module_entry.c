#include <stdio.h>
#include <stdlib.h>
#include "decision.c"
#include "../data_libs/data_io.c"


int main()
{
    int n;
    scanf("%d", &n);
    double *data = malloc(n*sizeof(double));

    input(data, n);

    if (make_decision(data, n))
        printf("YES");
    else
        printf("NO");

}
