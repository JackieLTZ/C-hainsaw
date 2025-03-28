#include <stdio.h>
#include <stdlib.h>
#define LENGTH 100

int getLength(const char *str);
char *getLine(char str[], int lim);
char *remakeLine(const char *str);

int main()
{
    int c;

    char *string = malloc((LENGTH + 1) * sizeof(char));

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
    int i;
    int len = getLength(str);
    const char *ptr = str;

    while (*ptr != '\0')
    {
        if (*ptr == ' ' || *ptr == '\t')
        {
            len += 1;
        }
        ptr++;
    }

    char *newString = malloc((len + 1) * sizeof(char));

    if (newString == NULL)
    {
        printf("Memory allocation failed!\n");
        abort();
    }

    ptr = str;
    char *pNew = newString;

    while (*ptr != '\0')
    {
        switch (*ptr)
        {
        case ' ':
            // \s - like 's'pace
            *pNew++ = '\\';
            *pNew++ = 's';
            break;
        case '\t':
            *pNew++ = '\\';
            *pNew++ = 't';
            break;
        default:
            *pNew++ = *ptr;
            break;
        }
        ptr++;
    }

    *pNew = '\0';
    return newString;
}

char *getLine(char *str, int lim)
{
    int c;
    char *ptr = str;

    while ((ptr - str) < lim - 1 && (c = getchar()) != EOF && c != '\n')
    {
        *ptr++ = c;
    }

    *ptr = '\0';

    return str;
}

int getLength(const char *str)
{
    int i = 0;

    while (*str != '\0')
    {
        i++;
        str++;
    }
    return i;
}