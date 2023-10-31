#include <stdio.h> 

int main(void)
{
    char panel[4][4];

    int i, j;
    for (i = 0; i < 4; i++)
    {
        printf("Enter ther color of the LED bulb in row %d (R, G, B): \n", i); 
        for (j = 0; j < 4; j++)
        {
            printf("\tcolumn %d: ", j);
            scanf(" %c", &panel[i][j]);
        }
    }

    printf("\n");
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("%c ", panel[i][j]); 
        }
        printf("\n");
    }


    printf("\n\nRed LED bulb positions\n");
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (panel[i][j] == 'R')
            {
                printf("[%d,%d] ", i, j);
            }
        }
    } 

    return 0; 
}