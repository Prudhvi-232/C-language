#include <stdio.h>
#include <string.h>
#include<math.h>

void numberToWords(int num){
    char *singledigit[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    char *doubledigit[] = {"", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    char *tens[] = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

    if (num >= 1000) {
        printf("%s Thousand ", singledigit[num / 1000]);
        num %= 1000;
    }
    if (num >= 100) {
        printf("%s Hundred ", singledigit[num / 100]);
        num %= 100;
    }
    if (num > 10 && num <= 19) {
        printf("%s ", doubledigit[num - 10]);
    } else if (num >= 20 || num==10) {
        printf("%s ", tens[num / 10]);
        num %= 10;
    }
    if (num >= 1 && num <= 9) {
        printf("%s ", singledigit[num]);
    }
}
int main() {
    int number;

    printf("Enter a number: ");
    scanf("%d", &number);

    if (number == 0) {
        printf("Zero\n");
    } else {
        numberToWords(number);
        printf("\n");
    }
    return 0;
}
/*
#include<stdio.h>
int main(){
    int num,num1,digit;
    printf("enter a number:");
    scanf("%d",&num);
    num1=num;
        while (num1>0)
        {            
            digit=num1%10;
            num1=num/10;
            
            if (digit==0){
            printf("zero");
            }
            if (digit==1){
            printf("one");
            }
            if (digit==2){
            printf("two");
            }
            if (digit==3){
            printf("three");
            }
            if (digit==4){
            printf("four");
            }  
            if (digit==5){
            printf("five");
            }
            if (digit==6){
            printf("six");
            }
            if (digit==7){
            printf("seven");
            }
            if (digit==8){
            printf("eight");
            }
            if (digit==9){
            printf("nine");
            }
            break;
            
        }
        return 0;
            }*/
        