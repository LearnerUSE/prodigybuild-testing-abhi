#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void print_arr(int *ptr, int size)
{
    putchar('[');
    while(size--)
    {
        printf("%d", *ptr++);
        if(size)
            putchar(',');
    }
    printf("]\n");
}

void swap(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

int *find_min(int *ptr, int size)
{
    int *min;

    min = ptr;
    while(size--)
    {
        if(*ptr < *min)
            min = ptr;
        ptr++;
    }
    return (min);
}

void selection_sort(int *ptr, int size)
{
    int *min;

    while(--size)
    {
        if((min = find_min(ptr + 1, size)))
        {
            if(*ptr > *min)
                swap(ptr, min);
        }
        ptr++;
    }
}

void fill(char **av, int *ptr, int size)
{
    int i;

    i = 2;
    while(av[i] && size--)
        *ptr++ = atoi(av[i++]); 
}

void test_print_arr()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Expected: [1,2,3,4,5]\n");
    printf("Actual: ");
    print_arr(arr, size);
}

void test_swap()
{
    int a = 5;
    int b = 10;

    printf("Before swap: a = %d, b = %d\n", a, b);
    swap(&a, &b);
    printf("After swap: a = %d, b = %d\n", a, b);
}

void test_find_min()
{
    int arr[] = {5, 2, 8, 1, 9};
    int size = sizeof(arr) / sizeof(arr[0]);

    int *min = find_min(arr, size);
    printf("Minimum element: %d\n", *min);
}

void test_selection_sort()
{
    int arr[] = {5, 2, 8, 1, 9};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Before sorting: ");
    print_arr(arr, size);

    selection_sort(arr, size);

    printf("After sorting:  ");
    print_arr(arr, size);
}

void test_fill()
{
    char *av[] = {"./your-executable-name", "5", "1", "2", "3", "4", "5"};
    int size = atoi(av[1]);
    int *arr = (int *)malloc(size * sizeof(int));
    assert(arr != NULL);

    fill(av, arr, size);

    printf("Filled array: ");
    print_arr(arr, size);

    free(arr);
}

int main(int argc, char *argv[])
{
    if(argc < 3)
    {
        puts("Usage: ./your-executable-name [array size] [array]");
        puts("Example: ./your-executable-name 3 2 1 0");
        return EXIT_FAILURE;
    }
    int size = atoi(argv[1]);
    if(!size)
    {
        puts("Error: size of array can't be 0");
        return EXIT_FAILURE;
    }
    int *arr = (int *)malloc(size * sizeof(int));
    if(!arr)
        return EXIT_FAILURE;
    fill(argv, arr, size);

    printf("Before sorting: ");
    print_arr(arr, size);

    selection_sort(arr, size);

    printf("After sorting:  ");
    print_arr(arr, size);

    free(arr);

    // Run unit tests
    test_print_arr();
    test_swap();
    test_find_min();
    test_selection_sort();
    test_fill();

    return EXIT_SUCCESS;
}