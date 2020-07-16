#include <stdio.h>
#include <stdlib.h>
main() {
    int* a;
    char* ch;
    int i = 0;
    int arr[10];
    a = (int*)malloc(sizeof(int)*2);
    ch = (char*)malloc(sizeof(char));

    for(i=-2; i<=(int)sizeof(char)+1; i++) {
        printf("\n %d %d %p", i, *(ch+i), (ch+i));
    }
    for(i=-2; i<=(int)sizeof(int)*2+1; i++) {
        printf("\n %d %d %p",i, *((char*) a+i), ((char*) a+i));
    }
    printf("\n%d---%d\n", *(a-1), *(a+10));
    return 0;
}
