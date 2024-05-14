#include <stdio.h>

int towerOfHanoi(int n, char source, char auxiliary, char destination) {
    int steps = 0;
    
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return 1; // Moving one disk requires 1 step
    }

    steps += towerOfHanoi(n - 1, source, destination, auxiliary);
    printf("Move disk %d from %c to %c\n", n, source, destination);
    steps += 1; // Increment steps for the current move
    steps += towerOfHanoi(n - 1, auxiliary, source, destination);

    return steps;
}

int main() {
    int numDisks;
    
    printf("Enter the number of disks: ");
    scanf("%d", &numDisks);

    if (numDisks < 1) {
        printf("Number of disks should be 1 or more.\n");
        return 1;
    }

    int totalSteps = towerOfHanoi(numDisks, 'A', 'B', 'C');
    
    printf("Total steps required: %d\n", totalSteps);

    return 0;
}
