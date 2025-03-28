#include <stdio.h>
#include <stdlib.h>
// #include <stdlib.h>
//
// void strncopy(char *dest, const char *src, size_t size);
// int strlena(const char *str);
//
// struct Point
// {
//     int x;
//     int y;
// };
//
// struct User
// {
//     char name[10];
//     int age;
//     float height;
// };
//
//
// int main(const int argc, char **argv)
// {
//     const struct Point pXY = {20, 15};
//     const int x = pXY.x;
//     const int y = pXY.y;
//     char *endptr;
//     printf("%d %d\n", x, y);
//
//     if (argc < 4)
//     {
//         printf("You need to pass more arguments");
//         return 1;
//     };
//
//     struct User u;
//
//     if (strlena(argv[1]) > 9)
//     {
//         puts("Yo");
//         return 1;
//     }
//
//     strncopy(u.name, argv[1], 10);
//     u.age = (int)strtol(argv[2], &endptr, 10);
//
//     if (*endptr != '\0') {
//         printf("Invalid input for age: '%s'\n", argv[2]);
//         return 1;
//     }
//
//     u.height = strtof(argv[3], &endptr);
//
//     if (*endptr != '\0') {
//         printf("Invalid input for height: '%s'\n", argv[3]);
//         return 1;
//     }
//
//     printf("%s, %d, %f\n", u.name, u.age, u.height);
//
//     return 0;
// }
//
// void strncopy(char *dest, const char *src, size_t size)
// {
//     if (dest == NULL || src == NULL || size == 0)
//         return;
//
//     while (size-- > 1 && (*dest++ = *src++) != '\0')
//         ;
//
//     *dest = '\0';
// }
//
// int strlena(const char *str)
// {
//     int n;
//
//     for (n = 0; *str++ != '\0'; n++)
//         ;
//
//     return n;
// }


#define MAX_BOOKS 5
#define MAX_TITLE_LEN 100
#define MAX_AUTHOR_LEN 100



struct Book
{
    char title[MAX_TITLE_LEN];
    char author[MAX_AUTHOR_LEN];
    int year;
};

void removeNewStr(char *str);
void inputBook(struct Book *book);
void printBook(const struct Book *book);

int main()
{
    struct Book library[MAX_BOOKS];

    int bookCount = 0;

    for (int i = 0; i < MAX_BOOKS; i++)
    {
        printf("Set up book number %d\n", i + 1);
        inputBook(&library[i]);
        bookCount++;

        if (i < MAX_BOOKS - 1)
        {
            char choice;
            printf("Do you want to add another book (y/n)? ");
            scanf(" %c", &choice);
            getchar();
            if (choice == 'n' || choice == 'N') {
                break;
            }
        }
    }

    printf("\nLibrary Collection:\n");
    for (int i = 0; i < bookCount; i++) {
        printf("\nBook %d:\n", i + 1);
        printBook(&library[i]);
    }

    return 0;
}

void inputBook(struct Book *book)
{
    printf("Please enter the title: ");
    fgets(book->title, MAX_TITLE_LEN, stdin);
    removeNewStr(book->title);

    printf("Please enter the author: ");
    fgets(book->author, MAX_TITLE_LEN, stdin);
    removeNewStr(book->author);

    char buff[5];
    printf("Please enter the year: ");

    if (fgets(buff, sizeof(buff), stdin))
    {
        char *endptr;
        const long value = strtol(buff, &endptr, 10);
        if (*endptr != '\0' && *endptr != '\n')
        {
            printf("Invalid number!\n");
        }
        else
        {
            book->year = (int)value;
        }
    }
    else
    {
        printf("Invalid input!\n");
    }
}

void printBook(const struct Book *book)
{
    printf("\nTitle: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Year: %d\n", book->year);
}

void removeNewStr(char *str)
{
    if (str == "" || str == NULL) return;

    while (*str != '\0')
    {
        str++;
    }

    if (*(str - 1) == '\n')
    {
        *(str - 1) = '\0';
    }
}