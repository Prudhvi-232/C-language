#include <stdio.h>
#include <math.h>

int main() {
    int dataset[] = {-5, 5, -3, -21, 58, -21, -49, 12, -60, 19, -20, -9, 11, 14, -34, 1, 10, 34, 10, 34};
    int n = sizeof(dataset) / sizeof(dataset[0]);
    
    double sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += dataset[i];
    }
    double mean = sum / n;
    
    double variance = 0;
    for (int i = 0; i < n; ++i) {
        variance += pow(dataset[i] - mean, 2);
    }
    variance /= n;
    double std_deviation = sqrt(variance);
    
    double skewness = 0;
    for (int i = 0; i < n; ++i) {
        skewness += pow((dataset[i] - mean) / std_deviation, 3);
    }
    skewness /= n;
    
    double kurtosis = 0;
    for (int i = 0; i < n; ++i) {
        kurtosis += pow((dataset[i] - mean) / std_deviation, 4);
    }
    kurtosis = kurtosis / n - 3; 
    
    printf("Mean: %.2f\n", mean);
    printf("Standard Deviation: %.2f\n", std_deviation);
    printf("Variance: %.2f\n", variance);
    printf("Skewness: %.2f\n", skewness);
    printf("Kurtosis: %.2f\n", kurtosis);
    
    return 0;
}