#include <stdio.h>
#include <stdbool.h>

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int unsorted[] = {5, 6, 4, 3, 9};
    int n = sizeof(unsorted) / sizeof(unsorted[0]);
    
    insertionSort(unsorted, n);
    
    printArray(unsorted, n);
    
    return 0;
}