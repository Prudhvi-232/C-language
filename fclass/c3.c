#include <stdio.h>

int main() {
    int rows = 5; 
    int spaces, numbers;

    for (spaces = 1; spaces <= rows; spaces++) {
        
        for (numbers = 1; numbers < spaces; numbers++) {
            printf(" ");
        }
        
    
        for (numbers = 1; numbers <= rows - spaces + 1; numbers++) {
            printf("%d ", numbers);
        }

        printf("\n");
    }

    return 0;
}