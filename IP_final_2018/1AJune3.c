#include <stdio.h> 
#include <assert.h>

float calDiscount (int time, float totAmount); 
void displayGift (float finalTot);
void testCalDiscount();

int main(void)
{
    int time; 
    float amount, finalTot, discount; 

    printf("Enter the hour: "); 
    scanf("%d", &time); 

    if (time < 0 || time > 23)
    {
        printf("Invalid time"); 
        return 1; 
    }

    printf("Enter the amount: "); 
    scanf("%f", &amount); 

    discount = calDiscount(time, amount);   
    finalTot = amount - discount; 

    printf("\nFinal amount: %.2f\n", finalTot); 

    displayGift(finalTot); 

    return 0;  
}

float calDiscount(int time, float amount)
{
    int discount; 
    if (time >= 16 && time <= 19)
    {
        discount =  amount >= 5000 ?  10 : amount >= 2500 ? 7 : 0;   
    }
    else if (time >= 20 && time <= 22)
    {
        discount =  amount >= 5000 ?  12 : amount >= 2500 ? 9 : 0;   
    }
    else 
    {
        discount = 0;
    }

    return amount / 100 * discount;  
}

void displayGift(float finalTot)
{
    if (finalTot >= 7000)
    {
        printf("Your gift: Packet of Milk");
    }
    else if (finalTot >= 5000)
    {
        printf("Your gift: 1kg of Sugar");
    }
    else if (finalTot >= 3000)
    {
        printf("Your gift: Pack of 6 Eggs");
    }
}

void testCalDiscount()
{
    assert(calDiscount(16, 5000) == 4500);
    assert(calDiscount(21, 5000) == 4400);
}