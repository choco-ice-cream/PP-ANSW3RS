#include <stdio.h> 

int main(void)
{
    FILE *file; 
    char name[10]; 
    int tel, i, telephone; 

    file = fopen("Directory.dat", "w");
    if (file == NULL)
    {
        printf("Error while opening the file"); 
        return 1;
    }

    for (i = 0; i < 5; i++)
    {
        printf("Enter a name: ");
        scanf("%s", name); 
        printf("Enter telephone no: "); 
        scanf("%d", &tel); 

        fprintf(file, "%s\t%d\n", name, tel);
    } 
    fclose(file);

    file = fopen("directory.dat", "r"); 
    if (file == NULL)
    {
        printf("Error while opening the file");
        return 1;
    }

    printf("\nEnter the telephone no: "); 
    scanf("%d", &telephone); 

    while (!feof(file))
    {
        fscanf(file, "%s\t%d\n", name, &tel); 

        if (tel == telephone)
        {
            printf("name: %s", name);
            break;
        }
    }

    fclose(file); 
    return 1; 
}