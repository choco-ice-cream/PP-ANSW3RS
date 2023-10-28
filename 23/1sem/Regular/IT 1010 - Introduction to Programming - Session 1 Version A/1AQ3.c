#include <stdio.h> 
#include <stdlib.h>
#include <assert.h>  

double PayableAmount(char vehicleType, int NumDays);
double paymentAfterTax(double payment);
void testpaymentAfterTax();

// main function
int main(void) 
{ 
    int days; 
    char v_type; 
    double payment, payment_after_tax;

    printf("Enter the vehicle type: ");
    scanf("%c", &v_type);

    printf("Enter the number of days: "); 
    scanf("%d", &days); 

    payment = PayableAmount(v_type, days);
    payment_after_tax = paymentAfterTax(payment);

    printf("Final payment: %.2lf\n", payment_after_tax);

    testpaymentAfterTax();

    return 0; 
}

// return payable amount with discount 
double PayableAmount(char vehicleType, int NumDays) 
{ 
    double rate; 
    rate = vehicleType == 'a' ? 5000.0 : 8000.0;

    if (NumDays <= 0)
    { 
        printf("wrong number of days"); 
        exit(1);
    }
    else if (NumDays <= 3) 
    { 
        return (NumDays * rate);
    }
    else if(NumDays <= 6) 
    { 
        return (NumDays * rate) - NumDays * rate / 100 * 10;  
    }
    else 
    { 
        return (NumDays * rate) - NumDays * rate / 100 * 20;   
    }
}

// return payment with tax
double paymentAfterTax(double payment)
{ 
    if (payment < 10000) 
    { 
        return payment;
    }
    else if (payment <= 15000)
    {
        return payment + payment / 100 * 5; 
    }
    else 
    { 
        return payment + payment / 100 * 10; 
    }
}

// testing 
void testpaymentAfterTax() 
{ 
    printf("\ntesting\n"); 

    // test 1
    double payment1 = 8000.0;
    double result1 = paymentAfterTax(payment1);
    assert(payment1 == result1);

    // test 2
    double payment2 = 12000.0;
    double result2 = paymentAfterTax(payment2);
    double expected2 = payment2 + payment2 / 100 * 5;
    assert(result2 == expected2);

    // test 3
    double payment3 = 20000.0;
    double result3 = paymentAfterTax(payment3);
    double expected3 = payment3 + payment3 / 100 * 10; 
    assert(result3 == expected3);

    printf("tests passed.\n"); 
}