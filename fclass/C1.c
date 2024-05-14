#include <stdio.h>
#include <math.h>
int main() {
    int units;
    float charge,bill;
    printf("enter no of units you have consumed:");
    scanf("%d",&units);
     if (units>=500)
        charge=5.50;
     else if (units>199 &&units<501)
        charge=3.50;
     else if (units<201 &&units>99)
        charge=2.50;
     else charge =1.50;
     bill=units*charge;
    printf("the charges for your consupsion of electricity is:%.2f",bill);
 
    return 0;
}