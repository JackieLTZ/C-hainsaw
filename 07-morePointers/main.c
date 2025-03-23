#include <stdlib.h>
#include <stdio.h>

#define MAX 100

int getIndex(const char *str, int c);
int strLen(const char *str);
void strCpy(char *dest, const char *src);
void strCat(char *dest, const char *src);
void strModify(char *dest, const char *src);
void reverse(char *str);
void toUpperCase(char *str);
void toLowerCase(char *str);
int strLenCmp(const char *str1, const char *str2);

int main(int argc, char **argv)
{
    // int x, y, i, c;

    // x = 1;
    // int buff[10];
    // for (i = 0; i < 10; i++)
    // {
    //     buff[i] = 0 + i;
    // }
    // int *pY;

    // pY = &buff[5];

    // y = *pY;
    // int *pX = &x;

    int i, c;

    char *newStr = malloc((MAX + 1) * sizeof(char));

    char *copyStr = malloc((MAX + 1) * sizeof(char));

    char *yo = malloc((MAX + 1) * sizeof(char));

    char *nP = newStr;

    for (i = 0; i < MAX - 1 && (c = getchar()) != EOF && c != '\n'; i++)
    {
        *nP++ = c;
    }

    *nP = '\0';

    char *string = " is a string";

    char *new = " hello-world-test ";

    int index = getIndex(string, 't');

    strCpy(copyStr, newStr);

    strCat(newStr, string);

    strModify(yo, new);

    printf("Org = %s\n", newStr);
    printf("org = %s\n", copyStr);
    printf("Oi = %s\n", newStr);
    printf("Yo = %s\n", yo);

    reverse(yo);

    printf("Yo1 = %s\n", yo);

    toUpperCase(yo);

    printf("Yo2 = %s\n", yo);

    toLowerCase(yo);

    printf("Yo3 = %s\n", yo);

    int result = strLenCmp(yo, newStr);

    int len1 = strLen(newStr);
    int len2 = strLen(yo);

    printf("len of newString is %d and yo is %d, then strLenCmp = %d\n", len1, len2, result);

    free(newStr);
    free(copyStr);
    free(yo);
}

int getIndex(const char *str, int c)
{
    int i = 0;
    while (*str != '\0')
    {
        if (*str == c)
        {
            return i;
        }
        str++;
        i++;
    }
    return -1;
}

int strLen(const char *str)
{
    int n;

    for (n = 0; *str != '\0'; str++)
    {
        n++;
    }

    return n;
}

void strCpy(char *dest, const char *src)
{
    while ((*dest++ = *src++) != '\0')
        ;
}

void strCat(char *dest, const char *src)
{
    while (*dest != '\0')
    {
        dest++;
    }

    while (*src != '\0')
    {
        *dest++ = *src++;
    }

    *dest = '\0';
}

void strModify(char *dest, const char *src)
{
    while (*src)
    {
        if (*src == '-')
        {
            src++;

            if (*src)
            {
                *dest++ = (*src >= 'a' && *src <= 'z') ? (*src - 32) : *src;
                src++;
            }
        }
        else
        {
            *dest++ = *src++;
        }
    }
    *dest = '\0';
}

void reverse(char *str)
{
    char *left = str;
    char *right = str;

    while (*right)
    {
        right++;
    }
    right--;

    while (right > left)
    {
        char temp = *left;
        *left = *right;
        *right = temp;

        left++;
        right--;
    }
}

void toUpperCase(char *str)
{
    while (*str != '\0')
    {
        *str = (*str >= 'a' && *str <= 'z') ? (*str - 32) : *str;
        str++;
    }
}

void toLowerCase(char *str)
{
    while (*str != '\0')
    {
        *str = (*str >= 'A' && *str <= 'Z') ? (*str + 32) : *str;
        str++;
    }
}

int strLenCmp(const char *str1, const char *str2)
{

    int i, j;

    i = j = 0;

    while (*str1 != '\0' || *str2 != '\0')
    {
        if (*str1)
        {
            str1++;
            i++;
        }

        if (*str2)
        {
            str2++;
            j++;
        }
    }

    if (i > j)
        return -1;
    if (i < j)
        return 1;

    return 0;
}