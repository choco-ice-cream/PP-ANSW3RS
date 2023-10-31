#include <stdio.h> 

struct course 
{
    int count; 
    float total_amount; 
}; 


int main(void)
{
    struct course hospitality, marketing, finance; 

    hospitality.count = 0; 
    hospitality.total_amount = 0; 
    marketing.count = 0; 
    marketing.total_amount = 0; 
    finance.count = 0; 
    finance.total_amount = 0; 

    int student_count = 0; 
    char course_type, answer; 


    while (student_count < 100)
    {


        if (answer == 'n' || answer == 'N')
        {
            break;
        }

        printf("Enter coure type: "); 
        scanf(" %c", &course_type); 

        if (course_type == 'H' || course_type == 'h')
        {
            hospitality.count++; 
            hospitality.total_amount += 1500; 
        }
        else if (course_type == 'M' || course_type == 'm')
        {
            marketing.count++; 
            marketing.total_amount += 2000; 
        }
        else if (course_type == 'f' || course_type == 'F')
        {
            finance.count++; 
            finance.total_amount += 2500; 
        }
        else 
        {
            printf("Invalide type.\n");
            continue;
        } 

        student_count++; 

        printf("\n\t\tREGISTRATION\n\n");
        printf("\t\t\t\tStudents\tTotal_amount\n");
        printf("Hospitality Management\t\t%d\t\t%.2f\n", hospitality.count, hospitality.total_amount);
        printf("Marketing\t\t\t%d\t\t%.2f\n",marketing.count, marketing.total_amount);
        printf("Finance \t\t\t%d\t\t%.2f\n",finance.count, finance.total_amount);
        printf("\n");

        
        printf("\nAre there more registraions (y/n): "); 
        scanf(" %c", &answer); 
        
    }
}