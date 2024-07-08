#include <stdio.h>

int binsearch(int yarr[], int size, int element)
{
    int left = 0;
    int right = size - 1;
    int mid;
    
    while (left <= right) {
        mid = (left + right) / 2;
        
        if (yarr[mid] == element) {
            return mid;
        }
        
        if (yarr[mid] < element) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return -1;
}

void test_binsearch()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    // Test cases
    printf("Searching for 5: %d\n", binsearch(arr, size, 5));
    printf("Searching for 10: %d\n", binsearch(arr, size, 10));
    printf("Searching for 1: %d\n", binsearch(arr, size, 1));
    printf("Searching for 11: %d\n", binsearch(arr, size, 11));
}

int main()
{
    test_binsearch();
    
    return 0;
}