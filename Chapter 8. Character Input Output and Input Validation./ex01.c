// Devise a program that counts the number of characters in its input up to the end of file.

#include <stdio.h>  

int main(void)
{
    unsigned int ch_ct = 0;
    while (getchar() != EOF)
    {
        ch_ct++;
    }
    printf("ch_ct = %u\n", ch_ct);
    return 0;
}