#include <stdio.h>
#define NMAX 10

int input(int *a, int n);
void sort(int *a, int n);
void output(int *a, int n);

int main() {
    int data[NMAX];
    int n = 10;

    input(data, n);
    sort(data, n);
    output(data, n);

    return 0;
}

int input(int *a, int n) {
    int i;
    for (i = 0; i < n; i++) {
        if (scanf("%d", &a[i]) != 1) {
            return 1;
        }
    }
    return 1;
}

void sort(int *a, int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void output(int *a, int n) {
    int i;
    for (i = 0; i < n; i++) {
        if (i == n - 1) {
            printf("%d", a[i]);
        } else {
            printf("%d ", a[i]);
        }
    }
    printf("\n");
}
