#include <stdio.h> 

int main(void)
{
    int id, tel;
    char name[10], answer; 
    FILE *file; 

    // open file 
    file = fopen("customers.dat", "a+"); 
    if (file == NULL) 
    {
        printf("Error while opening file");
        return 1; 
    }

    // main loop 
    while (1)
    {
        printf("Enter id: "); 
        scanf("%d", &id); 

        // check if id exist
        int temp, exist = 0;
        fseek(file, 0, SEEK_SET);     // set file pointer to 0
        while (!feof(file))
        {
            fscanf(file, "%d", &temp);
            if (temp == id)
            {
                printf("Id already exist.\n"); 
                exist = 1; 
                break;
            }

            fscanf(file, "%*[^\n]\n");    // skip a line 
        }

        if (exist)
        {
            continue; 
        }

        printf("Enter the name: "); 
        scanf("%s", name); 

        printf("Enter telephone no: "); 
        scanf("%d", &tel); 

        // add data to the file
        fprintf(file, "\n%d %s %d", id, name, tel); 

        printf("Do you want to add another customer (y/n): "); 
        scanf(" %c", &answer); 

        if (answer == 'n' || answer == 'N')
            break; 
    }

    fclose(file);
    return 0; 
}