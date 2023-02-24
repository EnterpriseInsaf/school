#include <stdio.h>
#include <stdlib.h>

int main ()
{
    long long n, p, del;
    scanf("%lld", &n);
    long long arr[n - 1];
    for (long long i = 0; i < n - 1; i++)
    {
        arr[i] = i + 2;
    }
    for (long long i1 = 0; i1 < n - 1; i1++)
    {
        if (i1 == 0) p = 2;
        else
        {
            for (long long i2 = p - 1; i2 < n - 1; i2++)
            {
                if (arr[i2] % p == 0) arr[i2] = 0;
            }
            for (long long i2 = p - 1; i2 < n - 1; i2++)
            {
                if (arr[i2] != 0)
                {
                    p = arr[i2];
                    break;
                }
            }
        }
    }
    for (long long i = 0; i < n - 1; i++)
    {
        if ((arr[i] != 0) && (n % arr[i] == 0)) del = arr[i];
        else {printf("n/a");}
    }
    printf("%lld", del);


}
