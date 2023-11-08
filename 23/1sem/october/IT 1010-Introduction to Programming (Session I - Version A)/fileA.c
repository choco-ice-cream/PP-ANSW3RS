#include <stdio.h> 

struct order 
{
    int r;
    int l;
};

int main(void)
{
    FILE *file; 
    int count = 0, answer; 
    struct order veggie = {0,0}, chicken = {0,0}, sea = {0,0};
    
    // open file
    file = fopen("orders.dat", "w");
    if (file == NULL)
    {
        printf("Error while opening the file"); 
        return 1; 
    }

    // get inputs and save in the file
    while (1)
    {
        char type, size; 
        int no;

        printf("\nType of the pizza (V/C/S): ");
        scanf(" %c", &type);
        printf("Size of the pizza (R/L): "); 
        scanf(" %c", &size); 
        printf("No of pizzas: "); 
        scanf("%d", &no);

        if (no == -1)
        {
            break;
        }

        fprintf(file, "%d %c %c %d\n", count, type, size, no);

        count++;
    }
    fclose(file); 

    // open file
    file = fopen("orders.dat", "r"); 
    if (file == NULL)
    {
        printf("Error while opening the file");
        return 1;
    }

    // read file 
    while (!feof(file))
    {
        char type, size; 
        int no;

        fscanf(file, "%*d %c %c %d\n", &type, &size, &no);

        if (size == 'R')
        {
            if (type == 'V')
                veggie.r += no; 
            if (type == 'C')
                chicken.r += no; 
            if (type == 'S')
                sea.r += no; 
        }
        else if (size == 'L')
        {
            if (type == 'V')
                veggie.l += no; 
            if (type == 'C')
                chicken.l += no; 
            if (type == 'S')
                sea.l += no; 
        }
    }
    fclose(file);

    // output
    printf("\nVeggie Pizza\n");
    printf("\tRegular\t-%d\n", veggie.r);
    printf("\tLarge\t-%d\n", veggie.l);
    printf("Chicken Pizza\n");
    printf("\tRegular\t-%d\n", chicken.r);
    printf("\tLarge\t-%d\n", chicken.l);
    printf("Seafood Pizza\n");
    printf("\tRegular\t-%d\n", sea.r);
    printf("\tLarge\t-%d\n", sea.l);
}