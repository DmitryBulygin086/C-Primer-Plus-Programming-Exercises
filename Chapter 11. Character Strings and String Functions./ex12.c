// Write a program that reads input up to EOF and reports the number of words, the
// number of uppercase letters, the number of lowercase letters, the number of punctuation
// characters, and the number of digits. Use the ctype.h family of functions.

#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    char ch;
    int word_ct = 0, upper_ct = 0, lower_ct = 0, punct_ct = 0, dig_ct = 0;
    bool inword = false;
    while ((ch = getchar()) != EOF)
    {
        //flush_input_buffer();
        if (!isspace(ch))
        {
            if (isalpha(ch))
            {
                if (!inword)
                {
                    inword = true;
                    word_ct++;
                }
                if (isupper(ch))
                {
                    upper_ct++;
                }
                else if(islower(ch))
                {
                    lower_ct++;
                }
            }
            else if (ispunct(ch))
            {
                punct_ct++;
                if (inword)
                {
                    inword = false;
                }
            }
            else if (isdigit(ch))
            {
                dig_ct++;
                if (inword)
                {
                    inword = false;
                }
            }
        }
        else 
        {
            if (inword)
            {
                inword = false;
            }
        }
    }

    printf("word_ct = %d\n", word_ct);
    printf("upper_ct = %d\n", upper_ct);
    printf("lower_ct = %d\n", lower_ct);
    printf("punct_ct = %d\n", punct_ct);
    printf("dig_ct = %d\n", dig_ct);
    putchar('\n');
    return 0;
}
