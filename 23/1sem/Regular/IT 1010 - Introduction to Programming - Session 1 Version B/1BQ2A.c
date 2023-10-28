#include <stdio.h> 

int main(void) 
{ 
    float proPrice[10], total, ave, low, total_than_200;
    int more_than_100; 

    for (int i = 0; i < 10; ++i) 
    {
        printf("enter the number %d: ", i + 1); 
        scanf("%f", &proPrice[i]);
    }

    total = 0; 
    low = proPrice[0];
    more_than_100 = 0;
    total_than_200 = 0; 

    for (int i = 0; i < 10; ++i) 
    { 
        total += proPrice[i]; 
        
        if (low > proPrice[i]) 
        { 
            low = proPrice[i]; 
        }

        if (proPrice[i] > 100) 
        { 
            ++more_than_100;
        }

        if (proPrice[i] > 200)
        { 
            total_than_200 += proPrice[i]; 
        }
    }
    
    printf("Average price: Rs.%.2f\n", total/10);
    printf("Lowest price: Rs.%.2f\n", low); 
    printf("Number of products more than Rs.100:%d\n", more_than_100); 
    printf("Total cost of products more than Rs.200.00:  Rs.%.2f\n", total_than_200);

    return 0; 
}