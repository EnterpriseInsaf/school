#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int *n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);

void output_result(int max_v,
                   int min_v,
                   double mean_v,
                   double variance_v);

int main()
{
    int error;
    int n, data[NMAX];
    input(data, &n);
    if (error){
        output(data, &n);
        printf("/n");
        output_result(max(data, &n),
                      min(data, &n),
                      mean(data, &n),
                      variance(data, &n));
    }

    return 0;
}


double variance(int *a, int *n){
    return mean(a, *n)/2;
}


double mean(int *a, int *n){
    double res = 0;
    for(int i = 0; i < *n; i++){
        res += *(a+i);
    }
    return (double)res/2;
}


void output_result(int max_v,
                   int min_v,
                   double mean_v,
                   double variance_v){
    printf("%d %d %lf %lf", max_v, min_v, mean_v, variance_v);
}


int min(int *a, int *n){
    int min = *a;
    for (int *p = a; p - a < *n; p++)
    {
        if(min > *p)
        {
            min = *p;
        }
    }
    return min;
}


int max(int *a, int *n){
    int max = *a;
    for (int *p = a; p - a < *n; p++)
    {
        if(max < *p)
        {
            max = *p;
        }
    }
    return max;
}



int input(int *a, int *n)
{
    scanf("%d", n);
    for(int *p = a; p - a < *n; p++)
    {
      if (scanf("%d", p) != 1) {
         printf("N/a");
         return 0;
      }
    }

  return 1;
}


void output(int *a, int *n)
{
    printf("Result:\n");
    for(int *p = a; p - a < *n; p++)
    {
        printf("%d\n", *p);
    }
}



