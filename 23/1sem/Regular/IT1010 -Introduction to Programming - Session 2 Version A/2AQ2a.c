#include <stdio.h> 

int main(void) 
{
    float marks[8], total = 0, max, low, diff, avg; 
    int i, high_students = 0; 

    // get input
    for (i = 0; i < 8; i++)
    {
        printf("Enter mark for student %d: ", i + 1);
        scanf("%f", &marks[i]); 
    }

    // get the max, min, total
    max = marks[0]; 
    low = marks[0];
    for (i = 0; i < 8; i++)
    {
        total += marks[i];

        if (max < marks[i])
            max = marks[i];
        
        if (low > marks[i])
            low = marks[i];

    }

    // calculate the average
    avg = total / 8; 

    // calculate no of students more than the average
    for (i = 0; i < 8; i++)
    {
        if (marks[i] > avg)
            high_students++; 
    }

    // output
    printf("Average mark: %.1f\n", avg);
    printf("Highest mark: %.1f\n", max); 
    printf("Number of students who obtained marks higher than the average mark: %d\n", high_students); 
    printf("The difference between highest and lowest marks of the students: %.1f\n", max - low); 

    return 0; 
}