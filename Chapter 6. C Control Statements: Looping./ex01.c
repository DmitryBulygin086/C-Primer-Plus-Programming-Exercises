// Write a program that creates an array with 26 elements and stores the 26 lowercase
// letters in it. Also have it show the array contents.

#include <stdio.h>

int main(void)
{   // creates an array with 26 elements
    char letters[26];

//    and stores the 26 lowercase letters in it
    
    for (int i = 0; i < 26; i++)  // i var is local to this for loop
    {
        letters[i] = 'a' + i;
    } // after loop i is undefined
    
    for (int i = 0; i < 26; i++)  // therefore we can declare i here
    {
        printf("%c", letters[i]);
        printf(" "); // spaces between each letter
    }

    return 0;
}