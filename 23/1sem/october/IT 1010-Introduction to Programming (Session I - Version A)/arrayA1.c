#include <stdio.h> 
#include <string.h>

int main(void)
{
    char strings[20]; 
    int i, j; 
    char c, temp; 

    // get input
    printf("Enter string  : ");
    scanf("%s", strings);
    i = strlen(strings) - 1;  

    // reverse the string  
    for (j = 0; j != (i + 1)/ 2; j++)
    {
        temp = strings[j]; 
        strings[j] = strings[i - j];
        strings[i - j] = temp; 
    }
    
    // output
    printf("Revered string: ");
    printf("%s", strings);
    return 0; 
}