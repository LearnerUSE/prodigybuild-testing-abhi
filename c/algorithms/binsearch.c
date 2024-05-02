#include <stdio.h>

int binsearch(int yarr[], int element)
{
    int size = sizeof(yarr) / sizeof(yarr[0]);
    int mid = size / 2;
    int left = mid;
    int right = size - left;
    extern int i;
    
    if(element == yarr[mid])
        printf("%d", yarr[mid]);
    
    if(element != yarr[right])
    {
        for(i = 0; i < left; i++)
        {
            if(element == yarr[i])
            {
                //Does this so that it doesn't print multiple times
                printf("%d", yarr[i]);
            }
        }
    }
}

int main(int argc, char *argv[])
{
    int arr[argc - 1];
    for(int i = 1; i < argc; i++)
    {
        arr[i - 1] = atoi(argv[i]);
    }
    binsearch(arr, atoi(argv[argc - 1]));
    return 0;
}