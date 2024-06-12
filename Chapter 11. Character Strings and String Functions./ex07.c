// The strncpy(s1,s2,n) function copies exactly n characters from s2 to s1, truncating
// s2 or padding it with extra null characters as necessary. The target string may not be
// null-terminated if the length of s2 is n or more. The function returns s1. Write your own
// version of this function; call it mystrncpy(). Test the function in a complete program
// that uses a loop to provide input values for feeding to the function.

#include <stdio.h>
#include <string.h>
#define STRLEN 50
char *mystrncpy(char *s1, char *s2, int n);
void s_gets(char *string, int n);
void flush_input_buffer(void);
int main(void)
{
    char srcString[STRLEN];
    char tarString[STRLEN];
    int size;
    puts("Enter a source string:");
    s_gets(srcString, STRLEN);
    while (srcString[0] != '\0')
    {
        printf("Enter an amount of characters do you want to copy: ");
        scanf("%d", &size);
        flush_input_buffer();

        mystrncpy(tarString, srcString, size);
        puts("tarString:");
        puts(tarString);
        putchar('\n');

        
        puts("Enter a source string:");
        s_gets(srcString, STRLEN);
    }
}

char *mystrncpy(char *s1, char *s2, int n)
{
    int i = 0;
    while (i < n && *s2 != '\0')
    {
        s1[i] = s2[i];
        i++;
    }
    while (i < n)
    {
        s1[i] = '\0';
        i++;
    }
    return s1;
}

void s_gets(char *string, int n)
{
    if (fgets(string, n, stdin) != NULL)
    {
        while(*string != '\0')
        {
            if (*string == '\n')
            {
                *string = '\0';
                break;
            }
            string++;
        }
    }
}

void flush_input_buffer(void)
{
    while (getchar() != '\n')
        continue;
}