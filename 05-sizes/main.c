#include <stdio.h>

void sq(char s[], int c);

int main()
{
    int i = 0;
    char c = 'c';
    float f = 1.2;
    double d = 1.2;

    printf("%lu, %lu, %lu\n", sizeof(i), sizeof(c), sizeof(d));

    char str[] = "string";

    printf("%s\n", str);

    sq(str, 's');

    printf("%s\n", str);
}

void sq(char s[], int c)
{
    int i, j;

    for (i = j = 0; s[i] != '\0'; i++)
    {
        if (s[i] != c)
        {
            s[j++] = s[i];
        }
    }
    s[j] = '\0';
}