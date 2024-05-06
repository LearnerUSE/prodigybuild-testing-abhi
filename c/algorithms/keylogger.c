#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void keylog()
{
    FILE *fPtr;
    fPtr = fopen("keylogger.txt", "a+");

    char a[2];
    fgets(a, sizeof(a), stdin);
    
    if(strlen(a) > 0)
        fprintf(fPtr, "%s", a);
    
    time_t now = time(NULL);
    struct tm *tm_struct = localtime(&now);
    int hour = tm_struct->tm_hour;
    
    if(hour == 24)
        fclose(fPtr);
}

int main()
{
    keylog();
    return 0;
}