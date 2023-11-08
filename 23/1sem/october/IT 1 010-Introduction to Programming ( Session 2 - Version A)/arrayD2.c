#include <stdio.h>

int main(void)
{
    int matrixS[4][4];
    int i, j, k, sym = 1;

    // get inputs
    for (i = 0; i < 4; i++)
    {
        printf("Values for row %d\n", i + 1); 
        for (j = 0; j < 4; j++)
        {
            printf("Enter element %d: ", j + 1);
            scanf("%d", &matrixS[i][j]); 
        }
        printf("\n");
    }

    // print the matrix
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("%d ", matrixS[i][j]);
        }
        printf("\n");
    }

    // check if it is symmetric
    for (i = 0, k = 1; i < 4; i++, k++)
    {
        for (j = k; j < 4; j++)
        {
            if (matrixS[i][j] != matrixS[j][i])
                sym = 0; 
        }
        k++;
    }

    if (sym)
    {
        printf("\nmatrix is symmetric");
    }
    else 
    {
        printf("\nmatrix is not symmetric");
    }
}