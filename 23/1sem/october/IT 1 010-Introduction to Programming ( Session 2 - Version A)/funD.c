#include <stdio.h> 
#include <assert.h> 

float calcPayment(int age, float size);
float calcSubsidy(float payment);
void displayDetails(float payment, float subsidy);

int main(void)
{
    assert(calcPayment(0, 10) == 21000); 
    assert(calcPayment(7, 5) == 10200);

    int i, age; 

    for (i = 1; i <= 3; i++)
    {
        float size, payment, subsidy; 
        printf("\nThe age of the paddy crops in week: ");
        scanf("%d", &age); 
        printf("The paddy field size in Hectare: "); 
        scanf("%f", &size);

        payment = calcPayment(age, size); 
        subsidy = calcSubsidy(payment);
        displayDetails(payment, subsidy);
    }
}

float calcPayment(int age, float size)
{
    float total; 
    int u = 0, t = 0, m = 0;

    if (age == 0)
    {
        t = 35;
    }
    else if (age == 2)
    {
        u = 30; 
    }
    else if (age == 4)
    {
        u = 65;
        m = 25;
    }
    else if (age == 6)
    {
        u = 50;
        m = 25;
    }
    else if (age == 7)
    {
        u = 30;
    }

    return (u * 68 + t * 60 + m * 70) * size; 
}

float calcSubsidy(float payment)
{
    return payment * 0.15; 
}

void displayDetails(float payment, float subsidy)
{
    printf("\nPayable amount \t\tSubsidy amount\n");
    printf("%.2f\t\t%.2f\n", payment - subsidy, subsidy);
}