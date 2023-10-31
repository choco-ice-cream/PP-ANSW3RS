#include <stdio.h> 

int main(void)
{
    FILE *file; 

    file = fopen("attendance.dat", "w"); 

    if (file == NULL) 
    {
        printf("Error opening the file\n"); 
        return 1; 
    }

    int i, id, j, k; 
    char name[10]; 
    
    for (i = 0; i < 2; i++)
    {
        printf("Enter Employee Number: "); 
        scanf("%d", &id);

        printf("Enter name: "); 
        getchar();
        fgets(name, sizeof(name), stdin);

        fprintf(file, "%d\n%s\n", id, name);

        printf("Enter attendance for: \n");
        for (j = 0; j < 7; j++)
        {
            printf("\tday %d: ", j + 1); 
            scanf("%d", &k);
            fprintf(file, "%d ", k);
        }

        fprintf(file, "\n");
    }

    fclose(file); 

    return 0; 
}