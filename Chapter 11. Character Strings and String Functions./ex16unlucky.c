// Write a program that reads input until end-of-file and echoes it to the display. Have the
// program recognize and implement the following command-line arguments:
// -p Print input as is
// -u Map input to all uppercase
// -l Map input to all lowercase
// Also, if there are no command-line arguments, let the program behave as if the –p
// argument had been used.

#include <stdio.h>
#include <ctype.h>

void map_uppercase(char *string);
void map_lowercase(char *stirng);
int main(int argc, char *argv[])
{
    
    if (argc == 2)
    {
        printf("%s", argv[1]);
    }

    if (argc < 2 || argc > 3 || (argc == 3) && argv[1][0] != '-')
    {
        printf("Usage: %s [-p || -u || -l] <input>\n", argv[0]);
        return 1;
    }

    else 
    {
        switch(argv[1][1])
        {
            case 'p' :
                printf("%s\n", argv[2]);
                break;
            case 'u' :
                map_uppercase(argv[2]);
                printf("%s\n", argv[2]);
                break;
            case 'l' :
                map_lowercase(argv[2]);
                printf("%s\n", argv[2]);
                break;
            default :
                printf("Usage: %s [-p || -u || -l] <input>\n", argv[0]);
                return 1;
        }
    }
    return 0;
}

void map_uppercase(char *string)
{
    while (*string != '\0')
    {
        if (islower(*string))
        {
            *string = toupper(*string);
        }
        string++;
    }
}

void map_lowercase(char *string)
{
    while (*string != '\0')
    {
        if (isupper(*string))
        {
            *string = tolower(*string);
        }
        string++;
    }
}