#include <stdio.h>
#include <stdbool.h>

int linsearch(int *yarr, int val, int size)
{
    for(int i = 0; i < size; i++)
    {
        if(yarr[i] == val)
        {
            return i;
        }    
    }
    return -1;
}

void test_linsearch()
{
    int yarr[] = {1, 2, 3, 4, 5};
    int size = sizeof(yarr) / sizeof(yarr[0]);
    
    // Test case 1: Element exists in the array
    int val1 = 3;
    int result1 = linsearch(yarr, val1, size);
    printf("Test case 1: %d\n", result1); // Expected output: 2
    
    // Test case 2: Element does not exist in the array
    int val2 = 6;
    int result2 = linsearch(yarr, val2, size);
    printf("Test case 2: %d\n", result2); // Expected output: -1
}

int main()
{
    test_linsearch();
    return 0;
}