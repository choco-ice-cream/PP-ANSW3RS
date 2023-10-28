#include <stdio.h> 

int main(void) 
{ 
    int A[2][3], B[3][3], C[2][3], temp;

    // get values for A matrix 
    printf("enter values for A: \n");
    for (int i = 0; i < 2; ++i) 
    {
        printf("row :%d\n", i); 
        for (int j = 0; j < 3; ++j)
        {
            printf("Enter column %d value: ", j);
            scanf("%d", &A[i][j]);
        }
    }

    // get values for B matrix 
    printf("enter values for B: \n");
    for (int i = 0; i < 3; ++i) 
    {
        printf("row :%d\n", i); 
        for (int j = 0; j < 3; ++j)
        {
            printf("Enter column %d value: ", j);
            scanf("%d", &B[i][j]);
        }
    }

    // multiply A and B matrix and get C
    for (int i = 0; i < 2; ++i)
    { 
        for (int j = 0; j < 3; ++j)
        { 
            temp = 0;
            for (int k = 0; k < 3; ++k)
            {
                temp += A[i][k] * B[k][j];
            }
            C[i][j] = temp; 
        }
    }

    // print A matrix 
    printf("A matrix\n"); 
    for (int i = 0; i < 2; ++i) 
    { 
        for (int j = 0; j < 3; ++j) 
        { 
            printf("|%d|", A[i][j]);
        }
        printf("\n"); 
    }
    printf("\n");

    // print B matrix 
    printf("B matrix\n"); 
    for (int i = 0; i < 3; ++i) 
    { 
        for (int j = 0; j < 3; ++j) 
        { 
            printf("|%d|", B[i][j]);
        }
        printf("\n"); 
    }
    printf("\n");

    // print C matrix 
    printf("C matrix\n"); 
    for (int i = 0; i < 2; ++i) 
    { 
        for (int j = 0; j < 3; ++j) 
        { 
            printf("|%d|", C[i][j]);
        }
        printf("\n"); 
    }

    return 0; 
}