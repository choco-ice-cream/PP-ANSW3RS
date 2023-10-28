#include <stdio.h> 

int main(void)
{
    int pid, guests; 
    float total; 
    char answer; 

    while (1)
    {
        // get input
        printf("Enter package Id: "); 
        scanf("%d", &pid); 

        if (pid == -99)
        {
            break; 
        }
        else if (pid > 4 || pid < 1)
        {
            printf("Invalid package id\n\n");
            continue; 
        }

        printf("Enter no of guests: "); 
        scanf("%d", &guests); 

        // calculate  amount for one customer  
        if (pid == 1)
        {
            total = 450;
        }
        else if (pid == 2)
        {
            if (guests <= 15)
            {
            total = 570;
            }
            else if (guests <= 30)
            {
                total = 640; 
            }
            else 
            {
                printf("Can't have more than 30 participants in this package. \n\n");
                continue; 
            }
        }
        else if (pid == 3)
        {
            total = 800;
        }
        else if (pid == 4)
        {
            total = 1050; 
        }

        total *= guests;    // calculate total

        // calculate additional payments and discounts
        if (pid == 3) 
        {
            printf("Do you need a birthday cake (Y/N)? "); 
            scanf(" %c", &answer); 

            if (answer == 'y' || answer == 'Y')
                total += 2800;

            printf("Do you need fire works (Y/N)? "); 
            scanf(" %c", &answer); 

            if (answer == 'y' || answer == 'Y')
                total += 2400;
        }
        else if (pid == 4)
        {
            printf("Do you want a photograph (Y/N)? "); 
            scanf(" %c", &answer); 

            if (answer == 'y' || answer == 'Y')
                total += guests * 900; 
                total -= total / 100 * 15; 
        }

        // output total amount
        printf("\nYou have selected package ID: %d\n", pid); 
        printf("Total charge for the event: %.2f\n\n", total); 
    }

    return 0; 
}