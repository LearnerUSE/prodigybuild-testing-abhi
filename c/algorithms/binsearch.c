#include <stdio.h>

int binsearch(int yarr[10], int element)
{
    int mid = 10 / 2;
    int left = mid;
    int right = 10 - 1;
    extern int i;
    
    if(element == yarr[mid])
        printf("%d\n", yarr[mid]);
    
    if(element != yarr[right])
    {
        for(i = 0; i < left; i++)
        {
            if(element == yarr[i])
            {
                printf("%d\n", i);
            }
        }
    }
}

int main(int argc, char* argv[])
{
    int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    binsearch(arr, 3);
}
