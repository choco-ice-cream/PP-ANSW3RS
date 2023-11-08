#include <stdio.h> 

int main(void)
{
    int identityArr[4][4]; 
    int i, j, identity = 1;

    // get inputs
    for (i = 0; i < 4; i++)
    {
        printf("Values for row %d\n", i + 1); 
        for (j = 0; j < 4; j++)
        {
            printf("Enter element 1: "); 
            scanf("%d", &identityArr[i][j]);
        }
    }

    // display matrix
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("%d ", identityArr[i][j]);
        }
        printf("\n");
    }

    // check diagonal
    for (i = 0; i < 4; i++)
    {
        if (identityArr[i][i] != 1)
        {
            identity = 0;
            break;
        }
    }

    // check if other elements are 0
    for (i = 1, j = 2; i < 3; i++)
    {
        for (;j < 4; j++)
        {
            if (identityArr[i][j] || identityArr[j][i])
            {
                identity = 0;
                break;
            }
        }
    }

    if (identity)
    {
        printf("Identity matrix ");
    }
    else 
    {
        printf("not Identity matrix ");

    }

}