#include <stdio.h>
#include <stdbool.h>

bool isEven(long num) {
    return num % 2 == 0;
}

void test_isEven() {
    // Test cases for even numbers
    printf("Testing even numbers...\n");
    printf("isEven(0) = %d\n", isEven(0));
    printf("isEven(2) = %d\n", isEven(2));
    printf("isEven(4) = %d\n", isEven(4));
    printf("isEven(6) = %d\n", isEven(6));
    printf("isEven(8) = %d\n", isEven(8));
    
    // Test cases for odd numbers
    printf("Testing odd numbers...\n");
    printf("isEven(1) = %d\n", isEven(1));
    printf("isEven(3) = %d\n", isEven(3));
    printf("isEven(5) = %d\n", isEven(5));
    printf("isEven(7) = %d\n", isEven(7));
    printf("isEven(9) = %d\n", isEven(9));
}

int main()
{
    long num;
    printf("Enter a number\n");
    scanf("%ld", &num);
    
    if (isEven(num)) {
        printf("Even");
    } else {
        printf("Odd");
    }
    
    test_isEven();
    
    return 0;
}