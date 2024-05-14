#include <stdio.h>

void segregatePositiveNegative(int arr[], int n) {
    int positive[n], negative[n];
    int positiveCount = 0, negativeCount = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] >= 0) {
            positive[positiveCount] = arr[i];
            positiveCount++;
        } else {
            negative[negativeCount] = arr[i];
            negativeCount++;
        }
    }
    for (int i = 0; i < positiveCount; i++) {
        arr[i] = positive[i];
    }

    for (int i = 0; i < negativeCount; i++) {
        arr[positiveCount + i] = negative[i];
    }
}

int main() {
    int n;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("enter %d element:",(i+1));
        scanf("%d", &arr[i]);
    }

    segregatePositiveNegative(arr, n);

    printf("Output after segregation: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}