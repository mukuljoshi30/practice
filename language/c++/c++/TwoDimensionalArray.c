#include <stdio.h>
#include <stdlib.h>

static int** create_array(int row, int column) 
{
    int i;
    int ** arr = (int**)malloc(sizeof(int*)*row);
    for(i = 0; i< row; i++) {
        arr[i] = (int*) malloc(sizeof(int)*column);
    } 
    return arr;
}

static int** create_array1(int row, int column) 
{
    int i;
    int length = (row*sizeof(int*))+(row*column*sizeof(int));
    int **arr = (int**)malloc(length);
    int *ptr = (int *)(arr + row); 
  
    // for loop to point rows pointer to appropriate location in 2D array 
    for(i = 0; i < row; i++) 
        arr[i] = (ptr + column * i); 
    return arr;
}

int main ()
{
    int** arr;
    int i, j, count=0;
    arr = create_array(3, 2);

    for(i=0; i<3; i++){
        for(j=0; j<2; j++)
        arr[i][j] = count++;
    }
    for(i=0; i<3; i++){
        for(j=0; j<2; j++)
            printf("%d \t", arr[i][j]);
        printf("\n");
    }
    return 0;
}