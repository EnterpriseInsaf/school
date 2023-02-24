#include "graph.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "rpn.h"

int main() {
    double final_result = 0;
    printf("Please select:1 for classic mode,2 for variable mode.\n");
    char choice = user_choice();
    while (choice != '1' && choice != '2') {
        printf("Invalid choice! Please input again!\n");
        choice = user_choice();
    }
    if (choice == '1') {
        char* arr = input_instructions();
        // arr = check_input(arr);
        final_result = calculator(arr, '1', " ", " ");
        free(arr);
    } else (choice == '2') {
        printf("Please enter the definition of your variable.\n");
        printf("Please do not use the same variable name as the functions above.\n");
        printf("Spaces are not allowed within the variable name.\n");
        char* variable = user_input();
        variable = check_def(variable);
        char* arr = input_instructions();
        arr = check_input(arr);
        final_result = second_mode(variable, arr);
        print_plot(arr);
        free(variable);
        free(arr);
    }
    // printf("final result %f\n", final_result);

    return 0;
}

char* field;

void plot_point(int x, int y) {
    int index = y * WIDTH + x;
    field[index] = '*';
}

char* allocate_field() { return (char*)malloc(WIDTH * HEIGHT * sizeof(char)); }

int print_plot(char* formula) {
    field = allocate_field();
    if (field == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        field[i] = '.';
    }

    for (int x = 0; x < WIDTH; x++) {
        double fx = X_MIN + x * (X_MAX - X_MIN) / WIDTH;
        double fy = calculator(formula, '2', "x", double_to_string(fx));
        if (fy >= Y_MIN && fy <= Y_MAX) {
            int y = HEIGHT - (int)((fy - Y_MIN) / (Y_MAX - Y_MIN) * HEIGHT);
            y = y < 0 ? 0 : y >= HEIGHT ? HEIGHT - 1 : y;
            plot_point(x, y);
        }
    }

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int index = y * WIDTH + x;
            putchar(field[index]);
        }
        putchar('\n');
    }

    free(field);
    return 0;
}
