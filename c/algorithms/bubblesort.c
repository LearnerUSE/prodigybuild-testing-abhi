#include <stdio.h>
#include <assert.h>

void bubble_sort(int *array, int len) 
{
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
    int test_array[] = {3, 9, 4, 8, 7, 6, 1, 2, 0, 10};
    int expected_array[] = {0, 1, 2, 3, 4, 6, 7, 8, 9, 10};
    
    bubble_sort(test_array, 10);
    
    for (int i = 0; i < 10; i++) {
        assert(test_array[i] == expected_array[i]);
    }
}

int main(void) 
{
    test_bubble_sort();

    printf("Unit tests pass.\n");
    return 0;
}