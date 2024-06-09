//Redo exercise 4 using a switch.

#include <stdio.h>

int main(void)
{
    char ch;
    unsigned int subs_ct = 0;
    while ((ch = getchar()) != '#')
    {
        switch(ch)
        {
            case '.' :
                putchar('!');
                subs_ct++;
                break;
            case '!' :
                printf("!!");
                subs_ct++;
                break;
            default :
                putchar(ch);
        }
    }
    printf("subs_ct = %u\n", subs_ct);
    return 0;
}