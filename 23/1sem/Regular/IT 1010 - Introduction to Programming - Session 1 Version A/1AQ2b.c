#include <stdio.h> 

int main(void)
{
    // make matrix and get values 
    int A[2][3], B[3][3], C[2][3];
    int i, j;

    // get input - A matrix
    printf("\nA matrix\n");
    for (i = 0; i < 2; ++i )
    { 
        printf("Enter value for row: %d\n", i);

        for (j = 0; j < 3; ++j)
        { 
            printf("\tcolumn: %d , value: ", j);
            scanf("%d", &A[i][j]);
        }
    }

    // get input - B matrix
    printf("\nB matrix\n");
    for (i = 0; i < 3; ++i )
    { 
        printf("Enter value for row: %d\n", i);

        for (j = 0; j < 3; ++j)
        { 
            printf("\tcolumn: %d , value: ", j);
            scanf("%d", &B[i][j]);
        }
    }

    // matrix multiplication
    for (i = 0; i < 2; ++i)
    { 
        
        for (j = 0; j < 3; ++j)
        { 
            int n, k;
            n = k = 0; 
            for (k = 0; k < 3; ++k)
            {
                n +=  (A[i][k]) * (B[k][j]);
            }
            C[i][j] = n;
        }
    }

    // print A matrix 
    printf("A matrix\n"); 
    for (i = 0; i < 2; ++i) 
    { 
        for (j = 0; j < 3; ++j) 
        { 
            printf("|%d|", A[i][j]);
        }
        printf("\n"); 
    }
    printf("\n");

    // print B matrix 
    printf("B matrix\n"); 
    for (i = 0; i < 3; ++i) 
    { 
        for (j = 0; j < 3; ++j) 
        { 
            printf("|%d|", B[i][j]);
        }
        printf("\n"); 
    }
    printf("\n");

    // print C matrix
    printf("\n");
    for (i = 0; i < 2; ++i)
    { 
        for (j = 0; j < 3; ++j)
        {
            printf("| %d |", C[i][j]);
        }
        printf("\n");
    }



    return 0; 
}