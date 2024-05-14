#include <stdio.h>

#define size 117 

int main() {
    int years[size];
    float temperatures[size];
    float tempChange[size - 1];
    float totaltemp = 0.0, avgtemp;
    float maxtemp = -100.0, mintemp = 100.0;
    int maxtempyear, mintempyear;

    FILE *fptr = fopen("temperatures.csv", "r");
    if (fptr == NULL) {
        printf("Error opening fptr");
        return 1;
    }
    for (int i=0;i<size;++i) {
        fscanf(fptr,"%d,%f",&years[i],&temperatures[i]);
        if(i>0){
            tempChange[i - 1] =(temperatures[i] - temperatures[i - 1])/temperatures[i - 1] * 100;
        }
        totaltemp+=temperatures[i];
        if(temperatures[i]>maxtemp) {
            maxtemp=temperatures[i];
            maxtempyear=years[i];
        }
        if(temperatures[i]<mintemp) {
            mintemp=temperatures[i];
            mintempyear=years[i];
        }
    }

    fclose(fptr);
    avgtemp=totaltemp/size;
    printf("a. Percentage change in temperature every five years starting from 1901:\n");
    for (int i = 0; i < size - 1; i += 5) {
        printf("%.2f%%\n", tempChange[i]);
    }
    printf("\n");
    printf("b. Average temperature: %.2f\n", avgtemp);
    printf("c. Year with maximum temperature: %d\n", maxtempyear);
    printf("   Year with minimum temperature: %d\n", mintempyear);

    return 0;
}