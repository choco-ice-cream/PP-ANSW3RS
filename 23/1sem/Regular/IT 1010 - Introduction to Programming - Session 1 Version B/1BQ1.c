#include <stdio.h> 

int main(void) 
{ 
    int sawan_type, no; 
    float total; 
    char order_type, answer; 

    // get 5 total number of orders
    for (int i = 0; i < 5; ++i) 
    { 
        // get sawan type 
        while (1) 
        {
            printf("Sawan type: "); 
            scanf("%d", &sawan_type); 

            if (!(sawan_type < 4 && sawan_type > 0)) 
            { 
                printf("wrong sawan type\n"); 
                while (getchar() != '\n');
                continue; 
            }
            break;
        }

        printf("No of Sawans: "); 
        scanf("%d", &no); 

        // calculate total 
        if (sawan_type == 1) 
        { 
            total = no * 10000;
        }
        else if (sawan_type == 2) 
        { 
            total = no * 12000;
        }
        else 
        { 
            total = no * 15000;
        }

        while (getchar() != '\n'); 
        printf("Order type: "); 
        scanf("%c", &order_type); 

        // calculate total with additional charges
        if (order_type == 'I') 
        { 
            total += total / 100.0 * 15;
        }
        else if (order_type == 'T') 
        { 
            total += total / 100.0 * 5;
        }
        else if (order_type == 'D') 
        {
            total += total / 100.0 * 5;
        }
        else 
        { 
            printf("wrong order type."); 
            return 1; 
        }

        printf("The amount to be paid: %.2f\n", total);

        // check if there are more orders to be taken 
        while (getchar() != '\n'); 
        printf("Do you want to input the next order details: ");
        scanf("%c", &answer); 

        if (answer == 'N')
        { 
            break;
        }
    }

    return 0;
}