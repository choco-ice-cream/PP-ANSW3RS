#include <stdio.h> 


int main(void)
{
    float arr[10], total, max, total_more_500 = 0; 
    int  i, no_less_100 = 0;

    // get the values 
    for (i = 0; i < 10; ++i)
    { 
        printf("Enter the value: "); 
        scanf("%f", &arr[i]); 
    }

    max = arr[0]; 
    for (int i = 0; i < 10; ++i)
    { 
        total += arr[i]; 

        // find max
        if (max < arr[i])
            max = arr[i]; 

        // find no of items less than 100
        if (arr[i] < 100)
            ++no_less_100;
        
        // total more than 500
        if (arr[i] > 500)
            total_more_500 += arr[i];
    }

   

    printf("\nAverage price: Rs.%.2f\n", total / 10.0); 
    printf("Highest price: Rs.%.2f\n", max); 
    printf("Number of products less than Rs.100:%d\n", no_less_100); 
    printf("Total cost of all the products that cost more than Rs.500: %.2f\n\n", total_more_500); 

    return 0;

}
