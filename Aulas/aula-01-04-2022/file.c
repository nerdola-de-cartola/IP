#include <stdio.h>

int main(void) {
    FILE a;

    printf("%d\n", a._mode);
    printf("%ld\n", a._offset);
    
    return 0;
}