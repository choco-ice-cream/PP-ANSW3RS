#include <stdio.h> 

struct movie 
{
    int balcony; 
    int normal; 
};

int main(void)
{
    FILE *file; 
    int i;
    struct movie harry = {0,0}, frozon = {0,0}, homes = {0,0}; 

    // open file 
    file = fopen("ticket.dat", "w"); 
    if (file == NULL)
    {
        printf("Error while opening the file "); 
        return 1; 
    }
     
    // get inputs and write to the file
    for (i = 0; i < 5; i++)
    {
        char movie, type; 
        int tickets;

        printf("\nEnter the movie type (H/F/S): ");
        scanf(" %c", &movie);
        printf("Enter the ticket type: "); 
        scanf(" %c", &type); 
        printf("Enter no of tickets: "); 
        scanf("%d", &tickets);

        fprintf(file, "%c %c %d\n", movie, type, tickets); 
    }
    fclose(file); 

    // open file
    file = fopen("ticket.dat", "r"); 
    if (file == NULL)
    {
        printf("Error while opening the file"); 
        return 1; 
    }
    
    // read file check file type
    while (!feof(file))
    {
        char type, movie; 
        int tickets; 

        fscanf(file, "%c %c %d\n", &movie, &type, &tickets);
        if (type == 'B')
        {
            if (movie == 'H')
                harry.balcony += tickets; 
            if (movie == 'F')
                frozon.balcony += tickets; 
            if (movie == 'S')
                homes.balcony += tickets; 
        }
        else if (type == 'N')
        {
            if (movie == 'H')
                harry.normal += tickets; 
            if (movie == 'F')
                frozon.normal += tickets; 
            if (movie == 'S')
                homes.normal += tickets; 
        }
    }
    
    // output
    printf("\nHarry Portor\n");
    printf("\tBalcony\t-%d\n", harry.balcony); 
    printf("\tNormal\t-%d\n", harry.normal); 
    printf("Frozon-II\n");
    printf("\tBalcony\t-%d\n", frozon.balcony); 
    printf("\tNormal\t-%d\n", frozon.normal); 
    printf("Sherlock Homes\n");
    printf("\tBalcony\t-%d\n", homes.balcony); 
    printf("\tNormal\t-%d\n", homes.normal); 

    fclose(file);
    return 0;   
}