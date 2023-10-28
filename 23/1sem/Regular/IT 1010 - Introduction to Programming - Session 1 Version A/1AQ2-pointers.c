#include <stdio.h> 

float ave(float arr[]); 
float highest(float arr[]); 
int less_than_100(float arr[]); 
float total_of_high(float arr[]); 
int get_input(char s[]); 
void get_items(char s, int *m, int rows, int columns); 
void print_matrix( int rows, int columns, int *matrix, char s); 
void matrix_multi(int rows_1, int columns_1, int columns_2, int columns, int *matrix_1, int *matrix_2, int *result); 

// main functions
int main(void) 
{ 

// part A
    float arr[10], average, max, total_more_500; 
    int  no_less_100;

    // get the values 
    for (int i = 0; i < 10; ++i)
    { 
        printf("Enter the value: "); 
        scanf("%f", &arr[i]); 
        while( getchar() != '\n'); 
    }

    average = ave(arr); 
    printf("\nAverage price: Rs.%.2f\n", average); 

    max = highest(arr); 
    printf("Highest price: Rs.%.2f\n", max); 

    no_less_100 = less_than_100(arr); 
    printf("Number of products less than Rs.100:%d\n", no_less_100); 

    total_more_500 = total_of_high(arr); 
    printf("Total cost of all the products that cost more than Rs.500: %.2f\n\n", total_more_500); 
    
// part B
    // get row and column values 
    int ar, ac, br, bc; 
    ar = get_input("Enter the A matrix no of rows: ");
    ac = get_input("Enter the A matrix no of columns: ");
    br = get_input("Enter the B matrix no of rows: ");
    bc = get_input("Enter the B matrix no of columns: ");

    // make matrix and get values 
    int A_matrix[ar][ac], B_matrix[br][bc], C_matrix[ar][bc];
    get_items('A', &A_matrix[0][0], ar, ac);
    get_items('B', &B_matrix[0][0], br, bc);

    matrix_multi(ar, ac, bc, bc, &A_matrix[0][0], &B_matrix[0][0], &C_matrix[0][0]);

    print_matrix(ar, ac, &A_matrix[0][0], 'A'); 
    print_matrix(br, bc, &B_matrix[0][0], 'B'); 
    print_matrix(ar, bc, &C_matrix[0][0], 'C'); 

}

//return the average of the array 
float ave(float arr[])
{ 
    float total; 
    total = 0; 
    for (int i = 0; i < 10; ++i)
    { 
        total += arr[i]; 
    }
    return (total / 10); 
}

// returns the highest value of the array 
float highest(float arr[])
{ 
    float max; 
    max = arr[0]; 
    for (int i = 1; i < 10; ++i)
    { 
        max = arr[i] > max ? arr[i] : max; 
    }
    return max; 
}

// returns the no of items that less than 100
int less_than_100(float arr[])
{ 
    int n; 
    n = 0;  

    for (int i = 0; i < 10; ++i)
    { 
        if (arr[i] < 100)
        { 
            ++n;   
        }
    }
    return n; 
}

// returns the sum of items that are more than 500
float total_of_high(float arr[]) 
{ 
    float total;
    total = 0.0; 

    for (int i = 0; i < 10; ++i)
    { 
        if (arr[i] > 500)
        { 
            total += arr[i];
        }
    }
    return total; 
}

// get input and clear input buffer 
int get_input(char s[])
{ 
    int n; 
    printf("%s", s);
    scanf("%d", &n); 
    while(getchar() != '\n'); 
    return n; 
}

// get items from input and store in the matrix 
void get_items(char s, int *m, int rows, int columns)
{ 
    printf("\n%c matrix\n", s);
    for (int i = 0; i < rows; ++i )
    { 
        printf("Enter value for row: %d\n", i);

        for (int j = 0; j < columns; ++j)
        { 
            printf("\tcolumn: %d , value: ", j);
            *(m + i * columns + j) = get_input(""); 
        }
    }
}

// print matrix 
void print_matrix(int rows, int columns, int *matrix, char s)
{ 
    printf("\n");
    for (int i = 0; i < rows; ++i)
    { 
        for (int j = 0; j < columns; ++j)
        {
            printf("| %d |", *(matrix + i * columns + j));
        }
        printf("\n");
    }
    
    return;
}

// matrix multiplication 
void matrix_multi(int rows_1, int columns_1, int columns_2, int columns, int *matrix_1, int *matrix_2, int *result)
{ 
    for (int i = 0; i < rows_1; ++i)
    { 
        
        for (int j = 0; j < columns_2; ++j)
        { 
            int n, k;
            n = k = 0; 
            for (k = 0; k < columns_1; ++k)
            {
                n +=  (*(matrix_1 + i * columns_1 + k)) * (*(matrix_2 + k * columns_2 + j));
            }
            *(result + i * columns + j) = n;
        }
        
    }
}