#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int *n);
void squaring(int *a, int *n);

int main()
{
    int n, data[NMAX];

    if (!input(data, &n)){
      return 0;
    }
    squaring(data, &n);
    output(data, &n);

    return 0;
}

int input(int *a, int *n)
{
    scanf("%d", n);
    if (*n > NMAX){printf("n/a"); return 0;}
    for(int *p = a; p - a < *n; p++)
    {
      if (scanf("%d", p) != 1) {
         printf("n/a");
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

void squaring(int *a, int *n)
{

    for(int *p = a; p - a < *n; p++)
    {
        *p *= *p;
    }
}
