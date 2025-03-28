#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void reverse(char *str);
int strLen(const char *str);
void toUpperCase(char *str);
void toLowerCase(char *str);
int getIndex(const char *str, int c);
void strCpy(char *dest, const char *src);
void strCat(char *dest, const char *src);
void strModify(char *dest, const char *src);
int strLenCmp(const char *str1, const char *str2);
void strModify1(char *dest, const char *src, size_t dest_size);

// MAIN

int main(int argc, char **argv)
{
    // int x, y, i, c;

    // x = 1;
    // int buff[10];
    // for (i = 0; i < 10; i++)
    // {
    //     buff[i] = i;
    // }
    // int *pY;

    // pY = &buff[5];

    // y = *pY;
    // int *pX = &x;

    int i, c;

    char *newStr = malloc((MAX + 1) * sizeof(char));

    if (newStr == NULL)
    {
        puts("no memory");
        abort();
    }

    char *copyStr = malloc((MAX + 1) * sizeof(char));

    if (copyStr == NULL)
    {
        puts("no memory");
        abort();
    }

    char *yo = malloc((MAX + 1) * sizeof(char));

    if (yo == NULL)
    {
        puts("no memory");
        abort();
    }

    char *nP = newStr;

    for (i = 0; i < MAX - 1 && (c = getchar()) != EOF && c != '\n'; i++)
    {
        *nP++ = c;
    }

    *nP = '\0';

    char *string = " is a string";

    char *new = "hello-world-test";

    int index = getIndex(string, 't');

    strCpy(copyStr, newStr);

    strCat(newStr, string);

    strModify(yo, new);

    printf("Org = %s\n", newStr);
    printf("Str = this%s, index=%d\n", string, index);
    printf("org = %s\n", copyStr);
    printf("Yo0 = %s\n", yo);

    reverse(yo);

    printf("Yo1 = %s\n", yo);

    toUpperCase(yo);

    printf("Yo2 = %s\n", yo);

    toLowerCase(yo);

    printf("Yo3 = %s\n", yo);

    int result = strLenCmp(yo, newStr);

    int len1 = strLen(newStr);
    int len2 = strLen(yo);

    const char *example = "ByeWorldLol";

    size_t buffer_size = strLen(example) + 3; // you can change it to check function behavior

    char *buffYo = malloc(buffer_size);

    if (buffYo == NULL)
    {
        puts("no memory");
        abort();
    }

    strModify1(buffYo, example, buffer_size);

    printf("Yo4 = %s\n", buffYo);

    printf("len of newString is %d and yo is %d, then strLenCmp = %d\n", len1, len2, result);

    free(newStr);
    free(copyStr);
    free(yo);
    free(buffYo);
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

void strModify1(char *dest, const char *src, size_t dest_size)
{
    const char *first = src;
    size_t required_size = 0;

    while (*src)
    {
        if ((*src >= 'A' && *src <= 'Z') && src != first)
            required_size += 2;
        else
            required_size++;

        src++;
    }

    if (required_size + 1 > dest_size)
    {
        printf("Error: Destination buffer is too small!\n");
        abort();
    }

    src = first;
    while (*src)
    {
        if ((*src >= 'A' && *src <= 'Z') && src != first)
        {
            *dest++ = '-';
            *dest++ = *src + 32;
            src++;
        }
        else if (src == first)
        {
            *dest++ = (*src >= 'A' && *src <= 'Z') ? (*src + 32) : *src;
            src++;
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

    while (*right != '\0')
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
        return 1;
    if (i < j)
        return -1;

    return 0;
}
