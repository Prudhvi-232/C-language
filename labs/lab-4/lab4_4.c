#include <stdio.h>
#include <math.h>

int main() {
    double purchase_price, down_payment, annual_interest_rate;
    int num_payments;
    printf("Enter the purchase price of the car: $");
    scanf("%lf", &purchase_price);
    
    printf("Enter the down payment: $");
    scanf("%lf", &down_payment);
    
    printf("Enter the annual interest rate (in percentage): ");
    scanf("%lf", &annual_interest_rate);
    
    printf("Enter the total number of payments (e.g., 36, 48, 60): ");
    scanf("%d", &num_payments);
    
    double monthly_interest_rate = (annual_interest_rate / 100) / 12;
    double principal = purchase_price - down_payment;
    double numerator = monthly_interest_rate * principal;
    double denominator = 1 - pow(1 + monthly_interest_rate, -num_payments);
    double monthly_payment = numerator / denominator;
    printf("Amount borrowed: $%.2lf\n", principal);
    printf("Monthly payment: $%.2lf\n", monthly_payment);
    return 0;
}
