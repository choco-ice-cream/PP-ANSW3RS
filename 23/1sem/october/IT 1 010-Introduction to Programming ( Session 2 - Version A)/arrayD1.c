#include <stdio.h>

int main(void)
{
    float rainArr[7];
    float total = 0, max, min; 
    int i, j;

    // get inputs
    for (i = 0; i < 7; i++)
    {
        printf("Input the rainfall of day %d: ", i + 1); 
        scanf("%f", &rainArr[i]);
    }

    // calculate average, min, max
    max = rainArr[0];
    min = rainArr[0]; 
    for (i = 1; i < 8; i++)
    {
        printf("Day 1 to %d\n", i);
        total += rainArr[i - 1];
        
        if (max < rainArr[i - 1])
            max = rainArr[i - 1];

        if (min > rainArr[i - 1])
            min = rainArr[i - 1];

        printf("Average rainfall: %.2fmm\n", total / i);
        printf("Maximum rainfall: %.2fmm\n", max); 
        printf("Minimum rainfall: %.2fmm\n", min); 
    }

    return 0;
}