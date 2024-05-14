#include <stdio.h>
void k_num(int arr[], int n, int k) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    int ksmall = arr[k-1];
    int klarge = arr[n-k];
    printf("%dth smallest element is %d \n%dth largest element is %d\n", k, ksmall, k, klarge);
}

int main() {
    int numofele, k, i;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &numofele);
    int arr[numofele];
    for (i = 1; i <= numofele; i++) {
        printf("print %d number:",i);
        scanf("%d", &arr[i]);
    }
    printf("Enter the value of k: ");
    scanf("%d", &k);

    k_num(arr, numofele, k);

    return 0;
}