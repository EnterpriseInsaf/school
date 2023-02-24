/*
    Search module for the desired value from data array.

    Returned value must be:
        - "even"
        - ">= mean"
        - "<= mean + 3 * sqrt(variance)"
        - "!= 0"

        OR

        0
*/


#include <stdio.h>
#define NMAX 30

void input(int *a, int *n);
double mean(int *a, int n);
double variance(int *a, int n);
int search(int *a, int *n);

int main(){
    int n, data[NMAX];
    int error;
    input(data, &n, &error);
    if(error){
        printf(search(data, n))
    }
    else
    {
        printf("n/a");
    }
}


double mean(int *a, int *n){
    double res= 0;
    for(int i = 0; i < *n; i++){
        res += *(a + i);
    }
    return(double)res / *n;
}


double variance(int *a, int *n){
    return mean(a, n) / 2;
}


int search(int *a, int *n){
    for(int i = 0; i < *n; i++){
        int res;
        if ((a[i] % 2 == 0) && (a[i] >= mean(a, n)) && (a[i] <= mean + 3)) * sqrt(variance(a, n)) && a[i] != 0){
            res = a[i];
        }
    }
    return res;
}




