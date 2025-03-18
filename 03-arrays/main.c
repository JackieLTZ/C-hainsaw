#include <stdio.h>

#define MAXLENGTH 1000

int getLine(char s[], int lim);
void copy(char to[], char from[]);

int main()
{
    int len, max;

    char string[MAXLENGTH];
    char longest[MAXLENGTH];

    max = 0;

    while ((len = getLine(string, MAXLENGTH)) > 0)
    {
        if (len > max)
        {
            max = len;
            copy(longest, string);
        }
    }

    if (max > 0)
        printf("The longest is: %s\n", longest);

    return 0;
}

int getLine(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n' && c != 'e'; ++i)
    {
        s[i] = c;
    }
    s[i] = '\0';
    return i;
}

void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
    {
        ++i;
    }
}

// int c, i, white, other;
// int ndigit[10];

// white = 0;
// other = 0;

// for (i = 0; i < 10; ++i)
// {
//     ndigit[i] = 0;
// }

// while ((c = getchar()) != EOF && c != 'e')
// {
//     if (c >= '0' && c <= '9')
//     {
//         ++ndigit[c - '0'];
//     }
//     else if (c == ' ' || c == '\n' || c == '\t')
//     {
//         ++white;
//     }
//     else
//     {
//         ++other;
//     }
// }

// printf("digits =");
// for (i = 0; i < 10; ++i)
// {
//     printf(" %d", ndigit[i]);
// }
// printf(" white spaces %d, other %d\n", white, other);

// // Stop