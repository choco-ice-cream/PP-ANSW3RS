#include <stdio.h> 

int main(void)
{
    float sales[2][3]; 
    float max; 
    int i, j, person = 1; 

    for (i = 0; i < 2; i++)
    {
        printf("Enter the sales amount of sales person %d.\n", i + 1); 
        for (j = 0; j < 3; j++)
        {
            printf("\tProduct %d: ", j + 1); 
            scanf("%f", &sales[i][j]); 
        }
        printf("\n"); 
    } 

    printf("The sales amount of 2 sales person for 3 products. \n\n");

    max = sales[0][0];
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%.2f\t", sales[i][j]); 

            if (sales[i][j] > max)
            {
                max = sales[i][j]; 
                person = i + 1;
            }
        }
        printf("\n"); 
    } 

    printf("\nThe sales person with the highest sales amount is sales person %d", person);

    return 0; 
}