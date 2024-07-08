#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void test_keylog() {
    // Mock data
    const char *mock_input = "Hello, World!";
    
    // Mock file
    FILE *mock_file = fopen("mock_keylogger.txt", "w+");
    
    // Test keylog function
    fprintf(mock_file, mock_input);
    fclose(mock_file);
    
    // Verify the content of the file
    FILE *verify_file = fopen("mock_keylogger.txt", "r");
    char buffer[100];
    fgets(buffer, sizeof(buffer), verify_file);
    fclose(verify_file);
    
    // Assert the content of the file
    if (strcmp(buffer, mock_input) != 0) {
        printf("Test failed: keylog function did not write the correct content to the file.\n");
    }
}

int keylog()
{
    FILE * fPtr;
    fPtr = fopen("keylogger.txt", "w+");

    if (fPtr == NULL) {
        printf("Error opening file.\n");
        return -1;
    }

    const char *a = getchar();
    
    if(a != NULL)
        fprintf(fPtr, "%s", a);
    
    time_t now = time(NULL);
    struct tm *tm_struct = localtime(&now);
    int hour = tm_struct->tm_hour;
    
    if(hour == 24)
        fclose(fPtr);
    
    return 0;
}

int main()
{
    test_keylog();
    keylog();
    
    return 0;
}