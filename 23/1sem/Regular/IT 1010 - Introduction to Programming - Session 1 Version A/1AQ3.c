#include <stdio.h> 
#include <stdlib.h>
#include <assert.h>  

double PayableAmount(char vehicleType, int NumDays);
double paymentAfterTax(double payment);
void testpaymentAfterTax();

// main function
int main(void) 
{ 
    testpaymentAfterTax();

    int days; 
    char v_type; 
    double payment, payment_after_tax;

    // get input
    printf("Enter the vehicle type: ");
    scanf("%c", &v_type);
    printf("Enter the number of days: "); 
    scanf("%d", &days); 

    payment = PayableAmount(v_type, days);
    payment_after_tax = paymentAfterTax(payment);

    // output
    printf("Final payment: %.2lf\n", payment_after_tax);

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
    assert(8000 == paymentAfterTax(8000));
    assert(22000 == paymentAfterTax(20000));
    assert(12600 == paymentAfterTax(12000));
}