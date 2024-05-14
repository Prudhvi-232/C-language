#include <stdio.h>

// Menu items  
float starters[3] = {200, 250, 300}; 
char* starterNames[3] = {"Soup", "Salad", "Sandwich"};

float mainCourse[3] = {300, 350, 400};
char* mainCourseNames[3] = {"Pasta", "Pizza", "Burger"};

// Order item structure
struct OrderItem {
  char name[100];
  float price;
  int qty;  
};

// Takes order by displaying menu and returns number of items ordered
int takeOrder(struct OrderItem orderedItems[]) {
  
  int choice;
  int numItems = 0;
  
  // Display starters menu 
  printf("--- Starters ---\n");
  for(int i = 0; i < 3; i++) {
    printf("%d. %s - Rs %.2f\n", i+1, starterNames[i], starters[i]); 
  }
  
  printf("Enter choice (0 to stop): ");
  scanf("%d", &choice);
  
  while(choice > 0) {
    if(choice <= 3) {
      orderedItems[numItems].price = starters[choice-1];
      strcpy(orderedItems[numItems].name, starterNames[choice-1]);  
      numItems++;
    } 
    printf("Enter choice (0 to stop): ");
    scanf("%d", &choice); 
  }
  
  // Display main course menu
  // User ordering logic same as above

  return numItems;
}


void generateBill(struct OrderItem orderedItems[], int numItems) {
  
  float total = 0; 
  
  printf("---- Bill Details ----\n");
  for(int i = 0; i < numItems; i++) {
    printf("%s x %d - Rs %.2f\n", orderedItems[i].name, 
                                  orderedItems[i].qty, 
                                  orderedItems[i].qty * orderedItems[i].price);
    
    total += orderedItems[i].qty * orderedItems[i].price;
  }
  
  printf("Total Amount = Rs %.2f", total);  
}

int main() {
  
  struct OrderItem orderedItems[10]; 
  
  int numItems = takeOrder(orderedItems);
  
  generateBill(orderedItems, numItems);
   
  return 0;
}