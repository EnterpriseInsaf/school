#include <stdio.h>
#include "data_stat.h"

double max(double *data, int n){
    double max = data[0];
        for (int i = 0; i < n; i++)
        {
            if(max < data[i])
            {
                max = data[i];
            }
        }
        return max;
}
double min(double *data, int n){
    double min = data[0];
        for (int i = 0; i < n; i++)
        {
            if(min > data[i])
            {
                min = data[i];
            }
        }
        return min;
}
double mean(double *data, int n){
    double res = 0;
        for(int i = 0; i < n; i++){
            res += data[i];
        }
        return (double)res/n;
}
double variance(double *data, int n){
    double mean_val = mean(data, n);
    double res = 0.0;
    for(int i = 0; i <n; i++){
        res += (data[i] - mean_val) * (data[i] - mean_val);
    }
    return res / n;
}
