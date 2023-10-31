#include <stdio.h> 

int main(void)
{
    FILE *file; 
    int id; 

    printf("Enter the ID: ");
    scanf("%d", &id); 

    // open the file
    file = fopen("attendance.dat", "r"); 
    if (file == NULL)
    {
        printf("Error while opening the file"); 
        return 1; 
    }

    int i, total = 0, temp_id, j;

    // read the file
    for (i = 0; i < 2; i++)
    {
        fscanf(file, "%d\n", &temp_id);

        if (id == temp_id)
        {
            fscanf(file, "%*[^\n]\n");      // skip a line

            // get total days
            int k; 
            for (k = 0; k < 7; k ++)
            {
                fscanf(file, "%d", &j);
                if (j == 1)
                    total++;
            }

            printf("Total number of worked days: %d", total);
            return 0; 
        }
        fscanf(file, "%*[^\n]\n");      //skip a line 
        fscanf(file, "%*[^\n]\n");      //skip a line 
    }

    printf("Id doesn't exist. \n"); 
    return 0;  
}