#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void swap(int *a, int *b);
int partition(int *a, int l, int h);
void quick_sort(int *a, int l, int h);

// Function to check if the array is sorted in ascending order
bool isSorted(int *arr, int size)
{
    for (int i = 1; i < size; i++)
    {
        if (arr[i] < arr[i - 1])
        {
            return false;
        }
    }
    return true;
}

// Function to print the array elements
void printArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf(" %d", arr[i]);
    }
    printf("\n");
}

// Unit tests
void testQuickSort()
{
    // Test case 1: Empty array
    int arr1[] = {};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    quick_sort(arr1, 0, size1 - 1);
    printf("Test case 1: ");
    if (isSorted(arr1, size1))
    {
        printf("Passed\n");
    }
    else
    {
        printf("Failed\n");
    }

    // Test case 2: Array with one element
    int arr2[] = {5};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    quick_sort(arr2, 0, size2 - 1);
    printf("Test case 2: ");
    if (isSorted(arr2, size2))
    {
        printf("Passed\n");
    }
    else
    {
        printf("Failed\n");
    }

    // Test case 3: Array with multiple elements
    int arr3[] = {5, 2, 8, 1, 9, 3};
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    quick_sort(arr3, 0, size3 - 1);
    printf("Test case 3: ");
    if (isSorted(arr3, size3))
    {
        printf("Passed\n");
    }
    else
    {
        printf("Failed\n");
    }
}

int main()
{
    int size;
    printf("Size: ");
    scanf("%d", &size);

    int *arr = malloc(size * sizeof(int));
    printf("Array elements: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    quick_sort(arr, 0, size - 1);

    printf("Sorted array:");
    printArray(arr, size);

    free(arr);

    // Run unit tests
    testQuickSort();

    return 0;
}

void swap(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
    return;
}

int partition(int a[], int l, int h)
{
    int i = l, j = l, p = h;

    while (i < h)
    {
        if (a[i] < a[p])
        {
            swap(&a[i], &a[j]);
            j++;
        }
        i++;
    }

    swap(&a[p], &a[j]);

    return j;
}

void quick_sort(int a[], int l, int h)
{
    int p;

    if (l < h)
    {
        p = partition(a, l, h);
        quick_sort(a, l, p - 1);
        quick_sort(a, p + 1, h);
    }

    return;
}