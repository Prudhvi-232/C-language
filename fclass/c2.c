#include <stdio.h>


int isPrime(int num) {
    if (num <= 1) {
        return 0; 
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0; 
        }
    }
    return 1; 
}


void findPrimesInInterval(int start, int end) {
    printf("Prime numbers between %d and %d are:\n", start, end);
    for (int i = start; i <= end; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    int start, end;

    printf("Enter the start of the interval: ");
    scanf("%d", &start);

    printf("Enter the end of the interval: ");
    scanf("%d", &end);

    findPrimesInInterval(start, end);

    return 0;
}