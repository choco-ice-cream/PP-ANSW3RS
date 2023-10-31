#include <stdio.h> 

#define T_COUNT 5

struct transaction {
    int acc_no; 
    char name[10]; 
    char type; 
    float amount; 
};

int main(void)
{
    struct transaction data[T_COUNT]; 

    int i; 
    for (i = 0; i < T_COUNT; i++)
    {
        printf("Enter account no: "); 
        scanf("%d", &data[i].acc_no); 

        printf("Enter name: "); 
        getchar();
        fgets(data[i].name, 10, stdin); 

        printf("Enter transaction type: "); 
        scanf(" %c", &data[i].type); 

        printf("Enter amount: "); 
        scanf("%f", &data[i].amount); 

        printf("\n");
    }

    float total_w = 0, total_d = 0; 
    int max_w = 0, max_d = 0; 

    for (i = 0; i < T_COUNT; i++)
    {
        if (data[i].type == 'D' || data[i].type == 'd')
        {
            total_d += data[i].amount; 
            if (data[max_d].amount < data[i].amount)
                max_d = i; 
        }
        else if (data[i].type == 'W' || data[i].type == 'w')
        {
            total_w += data[i].amount;
            if (data[max_w].amount > data[i].amount)
                max_w = i; 
        }
        else 
        {
            printf("Invalid");
            return 1; 
        }
    }

    printf("Total deposit amount: %.2f\n", total_d); 
    printf("Total withdrawal amount: %.2f\n", total_w); 
    printf("Name of the customer with the maximum deposit amount: %s", data[max_d].name); 
    printf("Name of the customer with the maximum withdrawal amount: %s", data[max_w].name); 

    return 0; 

}