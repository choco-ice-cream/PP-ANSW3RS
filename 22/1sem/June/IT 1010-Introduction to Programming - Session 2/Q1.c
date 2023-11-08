#include <stdio.h> 

int main(void)
{
    int n = -1; 
    int palindrome = 1;

    while (1)
    {
        printf("Enter a four digit number : "); 
        scanf("%d", &n); 

        if (n > 999 && n < 10000)
            break;

        printf("Invalid number.\n");
    }

    if ((n / 1000 != n %10) && (n % 1000 / 100 != n % 100 / 10))
        palindrome = 0;

    if (palindrome)
    {
        printf("it is a palindrome");
    }
    else
    {
        printf("it is not a palindrome");
    }
}