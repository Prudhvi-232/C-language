#include <stdio.h>
int main() {
  char check[100];
  int j;
  printf("enter a string:");
  fgets(check, sizeof(check), stdin);
  
  for (int i = 0; check[i] != '\0'; i++) {
    while (!(check[i] <= 'z' && check[i] >= 'a') && check[i] != '\0') {
      for (j = i; check[j] != '\0'; j++) {
        check[j] = check[j + 1];
      }
      check[j] = '\0';
    }
  }
  printf("%s", check);
  return 0;
}
