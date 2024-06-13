// Write a program with the following behavior. First, it asks you how many words you
// wish to enter. Then it has you enter the words, and then it displays the words. Use
// malloc() and the answer to the first question (the number of words) to create a dynamic
// array of the corresponding number of pointers-to-char. (Note that because each element
// in the array is a pointer-to-char, the pointer used to store the return value of malloc()
// should be a pointer-to-a-pointer-to-char.) When reading the string, the program should
// read the word into a temporary array of char, use malloc() to allocate enough storage
// to hold the word, and store the address in the array of char pointers. Then it should
// copy the word from the temporary array into the allocated storage. Thus, you wind up
// with an array of character pointers, each pointing to an object of the precise size needed
// to store the particular word. A sample run could look like this:
// How many words do you wish to enter? 5
// Enter 5 words now:
// I enjoyed doing this exerise
// Here are your words:
// I
// enjoyed
// doing
// this
// exercise

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LIMIT 400



/**
 * @brief Function to get n words from user input.
 *
 * This function reads n words from user input, dynamically allocates memory for each word,
 * and returns a pointer to an array of pointers to these words.
 *
 * @param n The number of words to read from user input.
 * @return A pointer to an array of pointers to the words.
 *         If memory allocation fails, returns NULL.
 *
 * @note The caller is responsible for freeing the memory allocated for the words.
 *       Use free(words_array[i]) for each word and free(words_array) to free the array itself.
 */
char **get_n_words(int n);


/**
 * @brief Function to find the end of a word in a given string.
 *
 * This function scans the string starting from the given word_start pointer,
 * and sets the word_end pointer to the first character that is not a space or null terminator.
 * It then moves the word_start pointer to the first character after the found word.
 *
 * @param word_start A pointer to a pointer to the start of the word in the string.
 *                   This pointer will be updated to point to the first character after the found word.
 * @param word_end   A pointer to a pointer to the end of the word in the string.
 *                   This pointer will be updated to point to the first character that is not a space or null terminator.
 *
 * @note This function assumes that the input string is null-terminated.
 *       It does not check for buffer overflow or other potential issues.
 */
void find_word_ends(char **word_start, char **word_end);

char *s_gets(char *s, int n);

void eat_newline(void);
int main(void) 
{
    int words_amount;
    char **words_array;
    while (1)
    {
        printf("How many words do you wish to enter? (<= 0 to quit): ");
        if (scanf("%d", &words_amount) != 1)
        {
            eat_newline();
            printf("Invalid input. Try again.\n");
            continue;
        }
        eat_newline();

        if (words_amount <= 0)
        {
            break;
        }

        words_array = get_n_words(words_amount);

        if (words_array != NULL)
        {
            printf("Here are your words:\n");
            for (int i = 0; i < words_amount; i++)
            {
                if (words_array[i][0] != '\0')  // if here's a not empty element of words_array
                    printf("%s\n", words_array[i]);
                free(words_array[i]);
            }
            free(words_array);
        }
        else 
        {
            printf("Memory allocation failed. Try again.\n");
            continue;
        }
    }
    puts("Goodbye!\n");
    return 0;
}

char **get_n_words(int n)
{
    char temp[LIMIT];
    char *word_start;
    char *word_end;
    int i;
    int word_len;

    char **words_array = (char **)malloc(sizeof(char *) * n);

    if (words_array != NULL)
    {
        printf("Enter %d words now:\n", n);
        word_start = s_gets(temp, LIMIT);
      

        for (i = 0; i < n; i++)
        {
            find_word_ends(&word_start, &word_end);

            // if word_start is pointing to null char,
            // there arn no more words to find; exit loop
            if (*word_start == '\0')
            {
                break;
            }

            word_len = word_end - word_start;
            words_array[i] = (char *)malloc(sizeof(char) * (word_len + 1));

            if (words_array[i] != NULL) // if memory allocation was successful
            {
                strncpy(words_array[i], word_start, word_len);
                words_array[i][word_len] = '\0';
            }

            word_start = word_end + 1;
        }

        // if less than n words were found,
        // free memory allocated for remaining of words_array
        for (;i < n; i++)
        {
            words_array[i] = (char *)malloc(sizeof(char));
            words_array[i][0] = '\0';
        }
    }
    return words_array;
}

void find_word_ends(char **word_start, char **word_end)
{
    while(isspace(**word_start))
    {
        (*word_start)++;
    }

    *word_end = *word_start;

    while (!isspace(**word_end) && **word_end != '\0')
    {
        (*word_end)++;
    }
}

void eat_newline(void)
{
    while (getchar() != '\n')
    {
        continue;
    }
}

char *s_gets(char *s, int n)
{
    char *ret_val;
    char *find;

    ret_val = fgets(s, n, stdin);
    if (ret_val)
    {
        find = strchr(s, '\n');
        if (find)
        {
            *find = '\0';
        }
        else
        {
            while (getchar()!= '\n')
            {
                continue;
            }
        }
    }
    return ret_val;
}