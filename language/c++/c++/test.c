#include <stdio.h>
#include <stdint.h>

int main() {
    uint32_t x;
    uint64_t y = 10000000000;
    x = y;
    
    printf("x=%u \t y=%llu \n",x,y );
    return 0;
}