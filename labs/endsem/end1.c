#include <stdio.h>
#include <string.h>

// Structure to store menu item  
struct menuItem {
  char name[50];
  float price;
};

// Structure to store order item
struct orderItem {
  char name[50];
  int quantity;
  float price;  
};

int printMainMenu() {
  printf("****************MENU****************\n"); 
  printf("1. Starters\n");
  printf("2. Main Course\n");
  printf("3. Desserts\n");
  printf("4. Beverages\n");
  
  int choice;
  scanf("%d", &choice);
  
  return choice;  
}

int printSubMenu(int mainChoice) {
  char starterFile[] = "starters.csv"; 
  char mainCourseFile[] = "maincourse.csv";
  char dessertFile[] = "desserts.csv";
  char beverageFile[] = "beverages.csv";
  
  // Open file as per main selection
  FILE* fp = NULL;
  if(mainChoice == 1) {
    fp = fopen(starterFile,"r"); 
  } else if (mainChoice == 2) {
    fp = fopen(mainCourseFile,"r");
  } else if (mainChoice == 3) {
    fp = fopen(dessertFile,"r"); 
  } else {  
    fp = fopen(beverageFile,"r");  
  }
  
  // Print submenu from file  
  printf("****************%d****************\n",mainChoice);
  
  char line[100];
  
  while(fgets(line,100,fp)) {
    printf("%s",line); 
  }  
  
  fclose(fp);
  
  return 0;
}

void generateBill() {

  // file handling code to open orders CSV 

  printf("--------Bill-------\n"); 
  printf("Item - Quantity - Price\n");
  
  // Print stored order details
  
  printf("------------------\n");
  printf("Total Amount: ");
  // Print total amount
  
  printf("-------------------\n");  
}

int main() {  
  int choice =  printMainMenu();
  
  while(1) {
    
    if(choice == 5)
      break;
      
    int subChoice = printSubMenu(choice); 
      
    printf("Enter item number to order: ");
    // Allow ordering items
      
    printf("Press 5 to generate bill");    
    scanf("%d",&choice);
  }     
  
  generateBill();
  
  return 0;  
}