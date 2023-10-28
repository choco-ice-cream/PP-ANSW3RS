#include <stdio.h> 

int main(void)
{ 
    // get input and write to the file
    FILE *file = fopen("Items.dat", "w"); 
    if (file == NULL) 
    { 
        printf("Error opening file"); 
        return 1; 
    }

    // get 5 input and store in the file
    for (int i = 0; i < 5; ++i)
    {
        int code;
        char name[30]; 

        printf("Enter item code: "); 
        scanf("%d", &code); 

        printf("Enter item name: "); 
        scanf("%s", &name);  

        fprintf(file, "%d\t%s\n", code, name); 
    }
    fclose(file);


    // read from the file and display item name 
    int item_code; 
    char name[30]; 
    int code;

    // get item code from user
    printf("Enter the item code: "); 
    scanf("%d", &item_code); 

    FILE *read_file = fopen("Items.dat", "r"); 
    if (read_file == NULL)
    { 
        printf("Error opening file"); 
        return 1; 
    }

    // search file and display item name
    while (!feof(read_file)) { 

        fscanf(read_file, "%d\t%s\n", &code, name);

        if ( code == item_code) 
        { 
            printf("Item name: %s", name); 
            fclose(read_file); 
            return 0;
        }
    }
    fclose(read_file);

    // item not found in file
    printf("Item code NOT found in file.");
    return 1;

}
