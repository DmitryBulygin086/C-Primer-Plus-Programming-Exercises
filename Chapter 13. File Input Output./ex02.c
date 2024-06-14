// Write a file-copy program that takes the original filename and the copy file from the
// command line. Use standard I/O and the binary mode, if possible.

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc!=3)
    {
        fprintf(stderr, "Usage: %s original copy\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    FILE *original;
    FILE *copy;
    char ch;
    original = fopen(argv[1], "rb");
    if (original == NULL)
    {
        fprintf(stderr, "Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    copy = fopen(argv[2], "wb");
    if (copy == NULL)
    {
        fprintf(stderr, "Can't open %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    while ((ch = getc(original))!= EOF)
    {
        putc(ch, copy);
    }
    fclose(original);
    fclose(copy);
    return 0;
    
}