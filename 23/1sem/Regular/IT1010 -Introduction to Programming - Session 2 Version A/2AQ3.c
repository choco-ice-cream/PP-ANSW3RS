#include <stdio.h>
#include <assert.h> 

double paymentAmount(int date, char cardType, double amount); 
void displayLoyaltytype(double payment); 
void testPaymentAmount();

int main(void)
{
    testPaymentAmount();

    double amount, payment;
    int date; 
    char card_type; 

    // get inputs
    printf("Enter date: "); 
    scanf("%d", &date); 

    printf("Enter card type: "); 
    scanf(" %c", &card_type); 

    printf("Enter amount: "); 
    scanf("%lf", &amount); 

    payment = paymentAmount(date, card_type, amount); 
    displayLoyaltytype(payment); 

    return 0; 
}

// calculate payment after deducting discount
double paymentAmount(int date, char cardType, double amount)
{
    if (date == 23 && cardType == 'a')
    {
        return amount - amount / 100 * 20; 
    }
    else if (date == 24 && cardType == 'b')
    {
        return amount - amount / 100 * 25; 
    }
    else if (date == 25 && cardType == 'c')
    {
        return amount - amount / 100 * 30; 
    }
    else if (date == 26 && (cardType == 'b' || cardType == 'c'))
    {
        return amount - amount / 100 * 20; 
    }
    else 
    {
        return amount; 
    }
}

// display loyalty type
void displayLoyaltytype(double payment)
{
    if (payment < 10000)
    {
        printf("Loyalty card type : Bronze"); 
    }
    else if (payment <= 25000)
    {
        printf("Loyalty card type : Silver"); 
    }
    else 
    {
        printf("Loyalty card type : Gold"); 
    }
}

// test paymentAmount function
void testPaymentAmount() 
{
    assert(paymentAmount(23, 'a', 20000) == 16000); 
    assert(paymentAmount(26, 'b', 10000) == 8000);
    assert(paymentAmount(10, 'a', 10000) == 10000); 
}