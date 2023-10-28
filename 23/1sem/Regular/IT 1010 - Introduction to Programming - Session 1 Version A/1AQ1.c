//program to calculate the total amount 

#include <stdio.h> 

//clear input buffer
void cl_buf(void);


int main(void) 
{   
    int sawan_type, no_sawan, orders; 
    float total, sawan[3] = {7000.0, 10000.0, 12000.0};
    char order_type, answer;  

    orders = 0; 
    for (orders = 0; orders < 5; ++orders) 
    { 
        // get the sawan type 
        while (1)
        {
            printf("Sawan type: "); 
            scanf("%d", &sawan_type); 
            cl_buf(); 

            if (!(sawan_type < 1 || sawan_type > 3)) 
            { 
                break; 
            }
            printf("invalid sawan type\n");
        }

        printf("No of Sawans: ");
        scanf("%d", &no_sawan); 
        cl_buf(); 

        // get the order type
        printf("Order type:"); 
        scanf("%c", &order_type);
        cl_buf(); 

        if (!(order_type == 'T' || order_type == 'I' || order_type == 'D'))
        {
            printf("invalid order type\n"); 
            return 1;
        }

        //calculate the total amount 
        total = sawan[sawan_type - 1] * no_sawan; 

        // add the service or delivery charges
        if (order_type == 'I') { 
            total += ((total / 100)* 5); 
        }else if (order_type == 'D') { 
            total += ((total / 100) * 10); 
        }

        // print the the total amount 
        printf("The amount to be paid: %.2f\n", total);


        if (orders != 4) 
        { 
            printf("Do you want to input the next order details: "); 
            scanf("%c", &answer);
            cl_buf();

            if (answer == 'N') { 
                return 0; 
            }
        }
    }
}

void cl_buf(void) 
{ 
    while (getchar() != '\n');
    return;
}