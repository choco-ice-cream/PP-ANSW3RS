#include <stdio.h> 

int main(void)
{
    int category;
    float bonus;  
    char answer = 'y'; 

    while (answer == 'y' || answer == 'Y')
    {
        printf("\nEnter employee category: "); 
        scanf("%d", &category); 


        if (category == 1) 
        {
            int rating;
            float salary; 

            printf("Enter basic salary: "); 
            scanf("%f", &salary); 
            
            printf("Performance rating (1-3): "); 
            scanf("%d", &rating); 

            bonus = salary * rating; 

        } 
        else if (category == 2)
        {
            int days; 
            float salary; 

            printf("Enter working days: "); 
            scanf("%d", &days); 

            printf("Daily payment: ");
            scanf("%f", &salary); 

            bonus = days > 240 ? salary * 20 : 0; 

        }
        else if (category == 3)
        {
            bonus = 50000; 
        }
        else 
        {
            printf("Invalid type\n"); 
            continue; 
        }

        printf("Employee bonus: %.2f\n", bonus); 

        printf("Do you want to continue (y/n)? ");
        scanf(" %c", &answer); 

        if (answer == 'n' || answer == 'N')
            break; 
    }

    return 0; 
}