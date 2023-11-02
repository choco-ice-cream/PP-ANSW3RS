#include <stdio.h> 
#include <assert.h> 

float calcInterest (int FDType, float depositAmount); 
float calcTax (float annualInterest);
void displayDetails(float interest, float taxAmount); 


int main(void)
{
    // testing calcInterest
    assert(calcInterest(1, 10000) == 1600); 
    assert(calcInterest(4, 1000) == 175);

    int type;
    double amount, interest, tax; 

    while (1)
    {
        printf("Enter deposit type: "); 
        scanf("%d", &type); 

        if (type == -1)
            break;
        else if (type < 1 || type > 4)
        {
            printf("Invalid type.\n\n");
            continue; 
        }

        printf("Enter depost amount: ");
        scanf("%lf", &amount);

        // calculate interest and tax
        interest = calcInterest(type, amount);
        tax = calcTax(interest); 
        displayDetails(interest, tax);
    }
}

float calcInterest (int FDType, float depositAmount)
{
    float rate; 

    if (FDType == 1)
    {
        rate = 16.0; 
    }
    else if (FDType == 2)
    {
        rate = 15.0; 
    }
    else if (FDType == 3)
    {
        rate = 15.5; 
    }
    else if (FDType == 4)
    {
        rate = 17.5;
    }

    return depositAmount / 100.0 * rate; 
}

float calcTax(float annualInterest)
{
    return annualInterest / 100.0 * 5; 
}

void displayDetails(float interest, float taxAmount)
{
    printf("\nAnnual Interest\t\tTax amount\tAmount Payable\n");
    printf("%.2lf\t\t\t%.2lf\t\t%.2lf\n\n", interest, taxAmount, interest - taxAmount);
}