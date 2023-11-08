#include <stdio.h> 

int main(void)
{
    int numArr[8] = {1,2,3,4,5,6,7,8};
    int n;

    printf("Enter a n: "); 
    scanf("%d", &n);

    int i,j;
    for (i = 0; i < n; i++)
    {
        int temp = numArr[7];
        for (j = 7; j > 0; j--)
        {
            numArr[j] = numArr[j - 1];
        }
        numArr[0] = temp; 
    }

    for (i = 0; i < 8; i++)
    {
        printf("%d ", numArr[i]);
    }
}