#include <stdio.h>
#include <stdlib.h>

void fibonacci()
{
    long a = 0;
    long b = 1;
    
    while (b > a)
    {
        a++;
        printf("%ld \n %ld\n", a, b);
    }
    
    if (b == sizeof(long))
    {
        exit(1);
    }
}

int main()
{
    fibonacci();
    
    return 0;
}