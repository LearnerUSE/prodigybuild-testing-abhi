#include <stdio.h>
#include <stdbool.h>

int binsearch(int yarr[], int size, int element)
{
    int left = 0;
    int right = size - 1;
    int mid;
    
    while (left <= right) {
        mid = left + (right - left) / 2;
        
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
    printf("Searching for 5: %d\n", binsearch(arr, size, 5)); // Expected output: 4
    printf("Searching for 10: %d\n", binsearch(arr, size, 10)); // Expected output: 9
    printf("Searching for 1: %d\n", binsearch(arr, size, 1)); // Expected output: 0
    printf("Searching for 11: %d\n", binsearch(arr, size, 11)); // Expected output: -1
}

int main(int argc, char *argv[])
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    test_binsearch();
    
    if (argc >= 3) {
        int element = atoi(argv[2]);
        int index = binsearch(arr, size, element);
        
        if (index != -1) {
            printf("Element %d found at index %d\n", element, index);
        } else {
            printf("Element %d not found\n", element);
        }
    }
    
    return 0;
}