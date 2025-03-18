#include <stdio.h>

#define IN 1
#define OUT 0

void noMain();

int main()
{
    int state = OUT;
    int d;
    double nl = 0.0;
    int nw, nc = 0;

    printf("Enter input (type 'e' to stop):\n");

    while ((d = getchar()) != EOF)
    {
        ++nc;
        if (d == '\n')
        {
            ++nl;
        }
        else if (d == 'e')
        {
            break;
        }
        putchar(d);

        if (d == ' ' || d == '\t' || d == '\n')
        {
            state = OUT;
        }
        else if (state == OUT)
        {
            state = IN;
            ++nw;
        }
    }

    printf("\nNumber of 'n' characters: %f\n", nl);
    printf("%d, %d\n", nw, nc);

    noMain();
    return 0;
}

void noMain()
{
    int c, state, nc;

    nc = 0;

    state = OUT;

    while ((c = getchar()) != EOF && c != 'e')
    {
        if (c != ' ' && c != '\t' && c != '\n')
        {
            ++nc;
            if (state == OUT)
            {
                state = IN;
            }
            putchar(c);
        }
        else if (state == IN)
        {
            state = OUT;
            putchar('\n');
        }
    }
    printf("%d chars\n", nc);
}