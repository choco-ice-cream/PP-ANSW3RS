#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 

double payableAmount(char vehicleType, int NumDays); 
double paymentAfterTax(double payment);
void testpaymentAfterTax(); 

int main(void) 
{
    int days; 
    char type; 
    double amount, total; 

    printf("Enter the vehicle type: "); 
    scanf("%c", &type); 

    printf("Enter the number of days: "); 
    scanf("%d", &days); 

    amount = payableAmount(type, days); 
    total = paymentAfterTax(amount); 

    printf("total : %.2f", total); 

    testpaymentAfterTax();

    return 0; 
}

// calculatin the rent with discount 
double payableAmount(char vehicleType, int NumDays)
{
    int rent; 
    rent = vehicleType == 'a' ? 4000 : 8000; 

    if (NumDays < 1)
    {
        printf("wrong number of days"); 
        exit(1); 
    }
    else if (NumDays < 3) 
    { 
        return NumDays * rent; 
    }
    else if (NumDays < 6)
    {
        return NumDays * rent - NumDays * rent / 100 * 10; 
    }
    else 
    { 
        return NumDays * rent - NumDays * rent / 100 * 20; 
    }
}

// calculating payment after tax
double paymentAfterTax(double amount) 
{ 
    if (amount < 10000) 
    { 
        return amount + amount / 100 * 5;
    }
    else if ( amount <= 15000) { 
        return amount + amount / 100 * 10;
    }
    else 
    { 
        return amount + amount / 100 * 20;
    }
}

// testing the paymentAfterTax function
void testpaymentAfterTax() 
{ 
    double amount1, amount2, amount3, result1, result2, result3, answer1, answer2, answer3; 

    printf("\n\ntesting...\n"); 

    // test 1 
    amount1 = 8000; 
    result1 = paymentAfterTax(amount1); 
    answer1 = amount1 + amount1 / 100 * 5;
    assert(result1 == answer1); 

    // test 2 
    amount2 = 12000; 
    result2 = paymentAfterTax(amount2); 
    answer2 = amount2 + amount2 / 100 * 10; 
    assert(result2 == answer2); 

    // test 3 
    amount3 = 20000; 
    result3 = paymentAfterTax(amount3); 
    answer3 = amount3 + amount3 / 100 * 20; 
    assert(result3 == answer3); 

    printf("done testing: passed\n");
}