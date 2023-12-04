#include <stdio.h>
#include <stdlib.h>

int fak(int n) {
    if (n <= 1) {
        return 1;
    } else {
        return n * fak(n-1);
    }
}

int main() {
    printf("fak(1): %d\n", fak(1));
    printf("fak(2): %d\n", fak(2));
    printf("fak(3): %d\n", fak(3));
    printf("fak(4): %d\n", fak(4));
    printf("fak(5): %d\n", fak(5));
    
    printf("fak(-1): %d\n", fak(-1));

    return 1;
}