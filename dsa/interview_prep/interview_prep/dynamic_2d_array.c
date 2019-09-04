/*
 * this program is to design a 2d array
 * using dynamic memory alloction.
 */
#include <stdio.h>
#include <stdlib.h>
/*
 * this function creates a two dimensional array
 * and returns the base address of it.
 * array[i][j] = array[i] + j
 *
 */
static int** create_array(int row, int col)
{
    int ** array;
    int i;
    /*
     * creating an array for saving row addresses
     */
    array = (int**) malloc(sizeof(int*)*row);
    /*
     * create an array of columns for each row.
     */
    for(i=0; i<row; i++) {
        array[i] = (int*) malloc(sizeof(int)*col);
    }
    return array;
}

/*
 * this can be done with a single malloc statement
 */
static int** create_array_v1(int row, int col)
{
    int **array;
    int len, i;
    int* ptr;
    
    /*
     * total leangth of the array
     * pointers to the rows + places for rows and col
     */
    len = sizeof(int*)*row + sizeof(int)*col*row;
    array = (int**)malloc(len);
    /*
     * first element for the array will be pointed out by ptr
     */
    ptr = (int*)(array+row);
    for(i = 0; i < row; i++) {
        array[i] = ptr +col*i;
    }
    return array;
}

/*
 * remove the dynamically allocated array
 */
void delete_array(int** array, int row)
{
    int i;
    for (i = 0; i<row; i++) {
        free(array[i]);
    }
    free(array);
}

void delete_array_v1(int** array)
{
    free(array);
}

int main()
{
    int** array;
    int col, row;
    int a[2][5], i, j;
    printf("\n enter the number of rows: ");
    scanf("%d", &row);
    printf("\n enter the numebr of columns: ");
    scanf("%d", &col);
    array = create_array(row, col);
    for (i=0; i<row; i++) {
        for (j=0; j<col; j++) {
            printf("\n %p", &array[i][j]);
            printf("\t %p \t %p", &array[i], array[i]);
        }
    }
    delete_array(array, row);
    
    array = create_array_v1(row, col);
    printf("\n======================");
    for (i=0; i<row; i++) {
        for (j=0; j<col; j++) {
            printf("\n %p", &array[i][j]);
            printf("\t %p \t %p", &array[i], array[i]);
        }
    }
    delete_array_v1(array);
    printf("\n");
    return 0;
}
