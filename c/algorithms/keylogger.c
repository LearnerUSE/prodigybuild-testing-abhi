#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int keylog()
{
    FILE * fPtr;
    fPtr = fopen("keylogger.txt", "w+");

    const char *a = malloc(sizeof(char));
    if(a == NULL)
        return 1;
    fgets(a, 2, stdin);
    
    if(a != NULL)
        fprintf(fPtr, "%s", a);
    
    time_t now = time(NULL);
    struct tm *tm_struct = localtime(&now);
    int hour = tm_struct->tm_hour;
    
    if(hour == 24)
        fclose(fPtr);
        
    free(a);
    return 0;
}

int main()
{
    keylog();
    return 0;
}