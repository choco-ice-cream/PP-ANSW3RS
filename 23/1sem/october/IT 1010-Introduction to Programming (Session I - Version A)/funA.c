#include <stdio.h> 
#include <assert.h> 

float calcPayment(int pType, float totalData);
float calcTax(float payment); 
void displayDetails(float payment, float tax); 

int main(void)
{
    assert(calcPayment(1, 1.5) == 120);
    assert(calcPayment(3, 11) == 1684);
    int pType; 
    float totalData, payment, tax; 

    // get inputs
    printf("Package Type: "); 
    scanf("%d", &pType); 
    printf("Total Data usage: "); 
    scanf("%f", &totalData); 

    payment = calcPayment(pType, totalData); 
    tax = calcTax(payment);
    displayDetails(payment, tax); 

    return 0; 
}

float calcPayment(int pType, float totalData)
{
    float fee = 0, extra = 0; 

    if (pType == 1)
    {
        fee = 120;
        if (totalData > 1.5)
            extra = (totalData - 1.5) * 1024 * 2;
    }
    else if (pType == 2)
    {
        fee = 350;
        if (totalData > 5)
            extra = (totalData - 5) * 1024 * 1.5;
    }
    else if (pType == 3)
    {
        fee = 660;
        if (totalData > 10)
            extra = (totalData - 10) * 1024 * 1;
    }
    else if (pType == 4)
    {
        fee = 1200;
        if (totalData > 20)
            extra = (totalData - 20) * 1024 * 0.5;
    }

    return fee + extra;  
}

float calcTax(float payment)
{
    return payment * 0.05 ; 
}

void displayDetails(float payment, float tax)
{
    printf("\nPayment\t\tTax amount\tMonthly bill payment\n");
    printf("%8.2f\t%.2f\t\t%.2f\n", payment, tax, payment + tax);
}