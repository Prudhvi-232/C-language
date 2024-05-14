#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 15
char stack_arr[MAX];
int top=-1;
void push(char c){
//overflow condition
  if (top==(MAX-1)) {
    printf("Stack is Full\n");
    return;
  } else{
    top=top+1;
    stack_arr[top]=c;
} }
void pop(){
  if (top==-1) {
    printf("Stack is Empty\n");
    exit(1);
  } else {
top=top-1; }
}
//to check if the new one and the one in the top of the stack are matching pairs

int pairs(char val1, char val2) {
  return ((val1== '(' && val2==')') || (val1=='[' && val2==']') ||
(val1=='{' && val2=='}'));
}
//to pop out matching pairs and check if its balanced or not
int balance(char expr[],int len) {
  for(int i=0;i<len;i++){
    if(expr[i]=='(' || expr[i]=='[' || expr[i]=='{'){
      push(expr[i]);
} else {
      if (top==-1){
        return 0;
      }else if(pairs(stack_arr[top], expr[i])) {
pop();
continue; }
return 0; }
}
return 1; }
int main() {
  char exp[MAX];
  int len;
  printf("Enter a string of brackets: ");
  fgets(exp,MAX,stdin);
  len=strlen(exp);
  if (exp[len-1] =='\n') {//since fgets takes /n when enter is pressed
    exp[len-1] ='\0';
}
  top=-1;
 len=strlen(exp);
  if(balance(exp,len)){
    printf("Balanced");
  } else{
    printf("Not Balanced");
}
return 0; 
}