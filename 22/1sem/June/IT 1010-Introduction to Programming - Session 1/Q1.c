#include <stdio.h> 

int main(void)
{
    int lines, i, j; 
    char s1, s2; 

    printf("Enter 1st character: "); 
    scanf(" %c", &s1); 
    printf("Enter 2nd character: "); 
    scanf(" %c", &s2); 
    printf("Enter number of lines: "); 
    scanf("%d", &lines);

    for (i = 0; i < lines; i++)
    {
        for (j = 1; j < i + 1; j++)
        {
            if (j % 2 == 0)
            {
                printf("%c", s2); 
            }
            else 
            { 
                printf("%c", s1); 
            }
        } 
        printf("\n");
    }
}