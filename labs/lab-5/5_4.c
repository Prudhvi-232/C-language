#include <stdio.h>

void findMaxMinSum(int arr[], int n) {
    int max_sum = 0, min_sum = 0;
    int max_element = arr[0], min_element = arr[0];

    for (int i = 0; i < n; i++) {
        if (arr[i] > max_element) {
            max_element = arr[i];
        }
        if (arr[i] < min_element) {
            min_element = arr[i];
        }
        max_sum += arr[i];
        min_sum += arr[i];
    }

    max_sum -= min_element;
    min_sum -= max_element;

    printf("Maximum Sum: %d\n", max_sum);
    printf("Minimum Sum: %d\n", min_sum);
}

int main() {
    int n;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

   
    for (int i = 0; i < n; i++) {
         printf("Enter the array element: ");
        scanf("%d", &arr[i]);
    }

    findMaxMinSum(arr, n);

    return 0;
}