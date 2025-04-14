#include <stdio.h>
#include <stdlib.h>

void writeInsideCLI(const char *filename);

int main()
{
    FILE *file;

    writeInsideCLI("lol.txt");

    file = fopen("lol.txt", "r");
    if (file == NULL)
    {
        perror("Failed to open file");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *myStr = (char *)malloc(fileSize + 1);
    if (myStr == NULL)
    {
        perror("Failed to allocate memory");
        fclose(file);
        return 1;
    }

    fread(myStr, 1, fileSize, file);
    myStr[fileSize] = '\0'; // Null-terminate the string

    printf("%s\n", myStr);

    free(myStr);
    fclose(file);

    return 0;
}

void writeInsideCLI(const char *filename)
{
    char userInput[100];

    int c;

    int i = 0;

    while ((c = getchar()) != EOF && c != '\n')
    {
        userInput[i] = c;
        i++;
    }

    userInput[i] = '\0';

    FILE *file = fopen(filename, "a");
    if (file == NULL)
    {
        perror("Failed to open file for writing");
        fclose(file);
        return;
    }
    fprintf(file, "%s\n", userInput);

    fclose(file);
}
