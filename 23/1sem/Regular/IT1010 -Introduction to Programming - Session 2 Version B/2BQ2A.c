#include <stdio.h> 

int main(void) 
{
    float stMarks[8], total = 0, max, low, diff, avg; 
    int i, low_students = 0; 

    // get input
    for (i = 0; i < 8; i++)
    {
        printf("Enter mark for student %d: ", i + 1);
        scanf("%f", &stMarks[i]); 
    }

    // get the max, min, total
    max = stMarks[0]; 
    low = stMarks[0];
    for (i = 0; i < 8; i++)
    {
        total += stMarks[i];

        if (max < stMarks[i])
            max = stMarks[i];
        
        if (low > stMarks[i])
            low = stMarks[i];

    }

    // calculate the average
    avg = total / 8; 

    // calculate no of students more than the average
    for (i = 0; i < 8; i++)
    {
        if (stMarks[i] < avg)
            low_students++; 
    }

    // output
    printf("Average mark: %.1f\n", avg);
    printf("Lowest mark: %.1f\n", low); 
    printf("Number of students who obtained marks lower than the average mark: %d\n", low_students); 
    printf("The difference between highest and lowest marks of the students: %.1f\n", max - low); 

    return 0; 
}