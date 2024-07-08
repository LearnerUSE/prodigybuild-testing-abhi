#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int count(int num) 
{
    printf("[");
    
    if(num > 20)
    {
        int i;
        for(i = 0; i < num; i++)
            printf("\n%d, \n", i);
            
        if(i == num + 1)
            printf("]");
    } else
    {
        int i;
        for(i = 0; i < num; i++)
            printf("%d", i);
            
        if(i == num)
            printf("]");
    }
}

int main()
{
    int num;
    printf("Count:~$ ");
    scanf("%d", &num);
    count(num);
}

// Unit tests

void test_count_less_than_20()
{
    printf("Expected output: [0123456789]\n");
    printf("Actual output: ");
    count(10);
    printf("\n");
}

void test_count_greater_than_20()
{
    printf("Expected output: \n[0, \n1, \n2, \n3, \n4, \n5, \n6, \n7, \n8, \n9, \n10, \n11, \n12, \n13, \n14, \n15, \n16, \n17, \n18, \n19, \n20, \n]\n");
    printf("Actual output: ");
    count(21);
    printf("\n");
}

void test_count_zero()
{
    printf("Expected output: []\n");
    printf("Actual output: ");
    count(0);
    printf("\n");
}

void test_count_negative()
{
    printf("Expected output: []\n");
    printf("Actual output: ");
    count(-5);
    printf("\n");
}

int main()
{
    test_count_less_than_20();
    test_count_greater_than_20();
    test_count_zero();
    test_count_negative();
    
    return 0;
}