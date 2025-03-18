#include <stdio.h>
#include <stdlib.h>
#define LENGTH 100

int getLength(const char *str);
char *getLine(char str[], int lim);
char *remakeLine(const char *str);

int main()
{
    int c;

    char *string = malloc(LENGTH * sizeof(char));

    if (string == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    getLine(string, LENGTH);

    char *newString = remakeLine(string);

    int l = getLength(string);
    int nL = getLength(newString);

    printf("The \"%s\" with length: %d\n", string, l);
    printf("The \"%s\" with length: %d\n", newString, nL);

    free(string);
    free(newString);

    return 0;
}

char *remakeLine(const char *str)
{
    int i, j;
    int len = getLength(str);

    int newLen = 0;
    for (i = 0; i < len; i++)
    {
        if (str[i] == ' ' || str[i] == '\t')
        {
            newLen += 2; // "\\s" or "\\t" takes 2 chars
        }
        else
        {
            newLen += 1;
        }
    }

    char *newString = malloc((newLen + 1) * sizeof(char));

    if (newString == NULL)
    {
        printf("Memory allocation failed!\n");
        abort();
    }

    for (i = 0, j = 0; i < len; i++)
    {
        switch (str[i])
        {
        case ' ':
            newString[j++] = '\\';
            newString[j++] = 's';
            break;
        case '\t':
            newString[j++] = '\\';
            newString[j++] = 't';
            break;
        default:
            newString[j++] = str[i];
            break;
        }
    }

    newString[j] = '\0';
    return newString;
}

char *getLine(char *str, int lim)
{
    int i, c;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
    {
        str[i] = c;
    }

    str[i] = '\0';

    return str;
}

int getLength(const char *str)
{
    int i = 0;

    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}