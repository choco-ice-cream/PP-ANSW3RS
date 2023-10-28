#include <stdio.h> 
#include <string.h> 

int main(void) 
{ 
    FILE *file = fopen("Items.dat", "w");  

    for (int i = 0; i < 5; ++i) 
    {
        char code[10], name[20];  

        printf("enter the item code: ");
        scanf("%s", &code); 
        printf("enter the item name: ");
        scanf("%s", &name); 
        fprintf(file, "%s\t%s\n", code, name);
    }
    fclose(file);

    char code[10];
    printf("enter a item code: "); 
    scanf("%s", &code);

    FILE *file_read = fopen("Items.dat", "r"); 

    while (!(feof(file_read))) 
    {
        char item_code[10], item_name[20]; 
        fscanf(file_read, "%s\t%s\n", item_code, item_name); 

        if (strcmp(code, item_code) == 0) 
        { 
            printf("\n%s\t%s\n", item_code , item_name); 
            fclose(file_read);
            return 0;
        }
    }
    fclose(file_read);

    printf("Item not found");
    return 1;
}