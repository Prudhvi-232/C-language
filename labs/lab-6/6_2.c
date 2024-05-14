#include <stdio.h>
int main() {
    char input_string[100];
    int vowels = 0, consonants = 0;
    
    printf("Enter a string: ");
    gets(input_string);

    for (int i = 0; input_string[i] != '\0'; i++) {
        char ch = input_string[i];
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
                ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
                vowels++;
            } else {
                consonants++;
            }
        }
    }

    printf("Total number of vowels: %d\n", vowels);
    printf("Total number of consonants: %d\n", consonants);

    return 0;
}

