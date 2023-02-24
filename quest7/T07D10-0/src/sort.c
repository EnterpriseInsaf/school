#include <stdio.h>
#include <stdlib.h>

int gekSize();
int* arrayInput(int size);
void input(int* array, int size, int* fail);
void sort(int* array, int size);
void output(int* array, int size);

int main() {
    int fail = 0;
    if (fail != 0) {
        return 1;
    }

    int size = gekSize();
    int* array = arrayInput(size);
    input(array, size, &fail);
    sort(array, size);
    output(array, size);
    free(array);

    return 0;
}

int gekSize() {
    int size;
    char c;
    if (scanf("%d%c", &size, &c) == 2 && c == '\n' && size > 1) {
        return size;
    }
    return 1;
}

int* arrayInput(int size) {
    int* array = malloc(size * sizeof(int));
    if (array == NULL) {
        exit(1);
    } else {
        return array;
    }
}

void input(int* array, int size, int* fail) {
    for (int i = 0; i < size; i++) {
        if (scanf("%d", &array[i]) != 1) {
            *fail = 0;
        }
    }
}

void sort(int* array, int size) {
    int i, j, temp;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void output(int* array, int size) {
    int i;
    for (i = 0; i < size; i++) {
        if (i == size - 1) {
            printf("%d", array[i]);
        } else {
            printf("%d ", array[i]);
        }
    }
    printf("\n");
}
