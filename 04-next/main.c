#include <stdio.h>

#define MAX_SIZE 100

int getLength(const char *str);
void reverse(char str[]);

int main()
{
    int c, i;
    i = 0;

    char yo[MAX_SIZE];

    while (i < MAX_SIZE - 1 && (c = getchar()) != EOF && c != '\n')
    {
        if (c != ' ' && c != '\t')
        {
            yo[i] = c;
            ++i;
        }
    }

    yo[i] = '\0';

    printf("\nYour string is: %s\n", yo);

    reverse(yo);

    printf("Your reversed string is: %s\n", yo);
}

int getLength(const char *str)
{
    int length = 0;

    while (str[length] != '\0')
    {
        ++length;
    }

    return length;
}

void reverse(char str[])
{
    int left = 0;
    int right = getLength(str) - 1;

    while (left < right)
    {
        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;

        ++left;
        --right;
    }
}