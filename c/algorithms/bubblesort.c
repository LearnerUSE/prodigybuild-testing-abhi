#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void bubble_sort(int *array, int len) 
{
    if (array == NULL || len <= 0) {
        return;
    }
    
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
            }
        }
    }
}

void test_bubble_sort() 
{
    // Test case 1: Empty array
    int *arr1 = NULL;
    bubble_sort(arr1, 0);
    // Expected output: No changes to the array
    
    // Test case 2: Array with one element
    int arr2[] = {5};
    bubble_sort(arr2, 1);
    // Expected output: No changes to the array
    
    // Test case 3: Array with multiple elements in ascending order
    int arr3[] = {1, 2, 3, 4, 5};
    bubble_sort(arr3, 5);
    // Expected output: No changes to the array
    
    // Test case 4: Array with multiple elements in descending order
    int arr4[] = {5, 4, 3, 2, 1};
    bubble_sort(arr4, 5);
    // Expected output: Array sorted in ascending order: {1, 2, 3, 4, 5}
    
    // Test case 5: Array with multiple elements in random order
    int arr5[] = {3, 9, 4, 8, 7, 6, 1, 2, 0, 10};
    bubble_sort(arr5, 10);
    // Expected output: Array sorted in ascending order: {0, 1, 2, 3, 4, 6, 7, 8, 9, 10}
    
    // Test case 6: Array with negative elements
    int arr6[] = {-5, -2, -10, -8, -3};
    bubble_sort(arr6, 5);
    // Expected output: Array sorted in ascending order: {-10, -8, -5, -3, -2}
    
    // Test case 7: Array with duplicate elements
    int arr7[] = {5, 2, 3, 5, 1, 2};
    bubble_sort(arr7, 6);
    // Expected output: Array sorted in ascending order: {1, 2, 2, 3, 5, 5}
    
    // Test case 8: Array with large number of elements
    int *arr8 = malloc(1000000 * sizeof(int));
    for (int i = 0; i < 1000000; i++) {
        arr8[i] = rand();
    }
    bubble_sort(arr8, 1000000);
    // Expected output: Array sorted in ascending order
    
    free(arr8);
}

int main(void) 
{
    test_bubble_sort();
    
    int yarr[] = {3, 9, 4, 8, 7, 6, 1, 2, 0, 10};
    
    bubble_sort(yarr, 10);

    printf("[");
    for (int i = 0; i < 10; i++)
        printf("%d, ", yarr[i]);	
    printf("\b\b]\n");
    return 0;
}