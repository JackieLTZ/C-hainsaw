#include <stdio.h>
#include <string.h>

int pLen(char *arr[]);
void changeName(char **arr, int index, char *newName);
void strcopy(char *dest, const char *src, size_t size);

int main(int argc, char *argv[])
{

    if (argc < 2)
    {
        printf("Usage: %s <word>\n", argv[0]);
        return 1;
    }

    char buff[4];

    strcopy(buff, argv[1], 4);

    if (strcmp(buff, "DOG") == 0)
        puts("WUF");
    else if (strcmp(buff, "CAT") == 0)
        puts("MEW");
    else
        puts("another");

    printf("Input was: ");
    for (int i = 0; i < 4; i++)
    {
        printf("%c", *(buff + i));
    }
    puts("");

    printf("Argv: ");
    while (argc-- > 0)
    {
        printf("%s%s", *argv++, (argc >= 1) ? " " : "");
    }
    puts("");

    static char *names[] = {
        "Ira",
        "Analdo",
        "Ronny",
        "Bobby",
    };

    char **pNames = names;
    while (*pNames)
    {
        printf("%s - ", *pNames);
        pNames++;
    }
    printf("End\n");
    changeName(names, 0, "Abba");

    pNames = names;

    while (*pNames)
    {
        printf("%s - ", *pNames);
        pNames++;
    }
    printf("End\n");

    printf("first %d\n", pLen(names));
}

int pLen(char **arr)
{
    char **pArr = arr;
    while (*pArr)
    {
        pArr++;
    }

    return pArr - arr;
}

void changeName(char **arr, int index, char *newName)
{
    *(arr + index) = newName; // same as arr[index] = newName
}

void strcopy(char *dest, const char *src, size_t size)
{
    while (--size > 0 && (*dest++ = *src++) != '\0')
        ;

    *dest = '\0';
}
