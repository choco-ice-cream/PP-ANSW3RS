#include <stdio.h> 

int main(void)
{
    // array ekata keybroad eken input ganna kamli hithuna   :D
    int numArr[8] = {1,2,3,4,5,6,7,8};
    int n, i, j;

    // get input
    printf("Enter no of positions to skip: "); 
    scanf("%d", &n);

    // reverse n no of time
    for (i = 0; i < n; i++)
    {

        // reverse one time 
        int temp = numArr[7];
        for (j = 7; j > 0; j--)
        {
            numArr[j] = numArr[j - 1];
        }
        numArr[0] = temp; 
    }

    // output
    for (i = 0; i < 8; i++)
    {
        printf("%d ", numArr[i]);
    }
}