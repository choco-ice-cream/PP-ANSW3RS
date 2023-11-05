#include <stdio.h> 

int main(void) 
{
    int image[5][5] = {0}; 
    int i, j, count = 0; 

    // get input
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            printf("pixel (%d, %d) black or white (1/0): ", i, j); 
            scanf("%d", &image[i][j]); 
        }
    }

    // display 2d array 
    printf("\n\n");
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            printf(" %d ", image[i][j]);
        }
        printf("\n\n");
    }

    // count 2 by 2 squares
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (image[i][j])
                continue;
            if (image[i][j] && image[i + 1][j] && image[i][j + 1] && image[i + 1][j + 1])
                count++; 
        }
    }

    printf("Number of 2 by 2 squares filed with all 1s : %d", count); 

    return 0; 
}