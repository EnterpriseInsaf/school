#ifndef GRAPH_H
#define GRAPH_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 80
#define HEIGHT 25
#define X_MIN 0
#define X_MAX 4 * M_PI
#define Y_MIN -1
#define Y_MAX 1
#define X_CENTER 0
#define Y_CENTER 13

char *field;
void plot_point(int x, int y);
char *allocate_field();
int print_plot(char *formula);

#endif