//program to calculate the total amount 

#include <stdio.h> 


int main(void) 
{   
    int sawan_type, no_sawan, orders; 
    float total, price;
    char order_type, answer;  

    orders = 0; 
    for (orders = 0; orders < 5; ++orders) 
    { 
        
        printf("Sawan type: "); 
        scanf("%d", &sawan_type); 

        if (sawan_type < 1 || sawan_type > 3)
        { 
            --orders; 
            printf("invalid sawan type\n\n");
            continue; 
        }

        printf("No of Sawans: ");
        scanf("%d", &no_sawan); 

        // get the order type
        printf("Order type:"); 
        scanf(" %c", &order_type);

        if (!(order_type == 'T' || order_type == 'I' || order_type == 'D'))
        {
            printf("invalid order type\n"); 
            return 1;
        }

        //calculate the total amount 
        price = sawan_type == 1 ? 7000 : sawan_type == 2 ? 10000 : sawan_type == 3 ? 12000 : 0;
        total = price * no_sawan;

        // add the service or delivery charges
        if (order_type == 'I') 
        { 
            total += (total / 100 * 5); 
        }
        else if (order_type == 'D') 
        { 
            total += (total / 100 * 10); 
        }

        // print the the total amount 
        printf("The amount to be paid: %.2f\n", total);


        if (orders != 4) 
        { 
            printf("Do you want to input the next order details: "); 
            scanf(" %c", &answer);

            if (answer == 'N' || answer == 'n') { 
                return 0; 
            }
            printf("\n");
        }
    }
}
