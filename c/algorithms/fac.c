#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int fak(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else if (n < 0) {
        return 1;
        exit(1);
    }
    return n * fak(n-1);
}

void test_fak() {
    // Test cases for positive numbers
    assert(fak(0) == 1);
    assert(fak(1) == 1);
    assert(fak(2) == 2);
    assert(fak(3) == 6);
    assert(fak(4) == 24);
    assert(fak(5) == 120);

    // Test case for negative number
    assert(fak(-1) == 1);
}

int main() {
    test_fak();

    printf("All tests passed.\n");

    return 0;
}