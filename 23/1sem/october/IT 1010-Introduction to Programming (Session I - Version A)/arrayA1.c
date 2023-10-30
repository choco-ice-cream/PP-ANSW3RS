#include <stdio.h> 

int main(void)
{
    char strings[20]; 
    int i, j; 
    char c, temp; 

    // get input
    printf("Enter string  : ");
    for (i = 0; i < 20; i++)
    {
        if ((c = getchar()) == '\n')
        {
            strings[i] = '\0';
            i--;
            break;
        } 

        strings[i] = c; 
    }

    // reverse the string  
    for (j = 0; j != (i + 1)/ 2; j++)
    {
        temp = strings[j]; 
        strings[j] = strings[i - j];
        strings[i - j] = temp; 
    }
    
    // output
    printf("Revered string: ");
    for (i = 0; i < 20 && strings[i] != '\0'; i++)
    {
        printf("%c", strings[i]); 
    }
    return 0; 
}