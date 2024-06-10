// Devise a function chline(ch,i,j) that prints the requested character in columns i
// through j. Test it in a simple driver.

#include <stdio.h>

void chline(char ch, unsigned i, unsigned j);

int main(void)
{
    char ch;
    unsigned uNum1, uNum2;
    printf("Enter a character and two integers: ");
    scanf("%c %u %u", &ch, &uNum1, &uNum2);
    chline(ch, uNum1, uNum2);
    putchar('\n');
    return 0;
}

void chline(char ch, unsigned i, unsigned j)
{
    unsigned count;
    for (count = 1; count < i; count++)
    {
        putchar(' ');
    }
    for(; count <= j; count++)
    {
        putchar(ch);
    }
}
