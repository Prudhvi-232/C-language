#include <stdio.h>
int main() {
    int n,Duplicate=0,uniqueCount=0;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    int unique[n]; 

    for (int i = 0; i < n; i++) {
        printf("enter the %d element: ",(i+1));
        scanf("%d", &arr[i]);
    }
    printf("original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
        for (int j = 0; j < uniqueCount; j++) {
            if (arr[i] == unique[j]) {
                Duplicate = 1;
                break;
            }
        }
        if (!Duplicate) {
            unique[uniqueCount] = arr[i];
            uniqueCount++;
        }
    }
    printf("\nArray without duplicates: ");
    for (int i = 0; i < uniqueCount; i++) {
        printf("%d ", unique[i]);
    }

    printf("\n");

    return 0;
}
