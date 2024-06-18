// Modify Listing 14.14 so that as each record is read from the file and shown to you, you
// are given the chance to delete the record or to modify its contents. If you delete the
// record, use the vacated array position for the next record to be read. To allow changing
// the existing contents, you’ll need to use the "r+b" mode instead of the "a+b" mode, and
// you’ll have to pay more attention to positioning the file pointer so that appended records
// don’t overwrite existing records. It’s simplest to make all changes in the data stored in
// program memory and then write the final set of information to the file. One approach to
// keeping track is to add a member to the book structure that indicates whether it is to be
// deleted.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 10      /* maximum number of books */
char * s_gets(char * st, int n);
struct book {
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};
void eatline(void);

void modify_record(struct book * record);
int main(void)
{
    struct book library[MAXBKS]; /* array of structures*/
    int count = 0;
    int index, filecount;
    FILE * pbooks;
    int size = sizeof(struct book);
    char choice;

    if ((pbooks = fopen("book.dat", "r+b")) == NULL)
    {
        fputs("Can't open book.dat file\n", stderr);
        exit(1);
    }

    rewind(pbooks);
    while (count < MAXBKS && fread(&library[count], size,
                       1, pbooks) == 1)
    {
        if (count == 0)
            puts("Current contents of book.dat:");
        printf("%s by %s: $%.2f\n", library[count].title,
               library[count].author, library[count].value);
        
        printf("Enter your choice:\n");
        printf("n) next book           d)delete this record\n");
        printf("m) modify this record\n");
        choice = getchar();
        eatline();

        switch(choice)
        {
            case 'N' :
            case 'n' :
                break;
            
            case 'M' :
            case 'm' :
                modify_record(&library[count]);
                break;

            case 'D' :
            case 'd' :
                count--;
                break;
            default :
                fprintf(stderr, "Invalid input. n) next books was choosen automaticaly\n");
                continue;
        }

        count++;
    }
    filecount = count;
    if (count == MAXBKS)
    {
        fputs("The book.dat file is full.", stderr);
        exit(2);
    }

    puts("Please add new book titles.");
    puts("Press [enter] at the start of a line to stop.");
    while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL
         && library[count].title[0] != '\0')
    {
        puts("Now enter the author.");
        s_gets(library[count].author, MAXAUTL);
        puts("Now enter the value.");
        scanf("%f", &library[count++].value);
        while (getchar() != '\n')
            continue;    /* clear input line */
        if (count < MAXBKS)
            puts("Enter the next title.");
    }


    if ((pbooks = fopen("book.dat", "w+b")) == NULL)
    {
        fprintf(stderr, "Could not open book.dat file for writing.\n");
        exit(EXIT_FAILURE);
    }
    if (count > 0)
    {
        puts("Here is the list of your books:");
        for (index = 0; index < count; index++)
            printf("%s by %s: $%.2f\n", library[index].title,
                    library[index].author, library[index].value);
        fwrite(library, size,count,
            pbooks);
    }
    else 
        puts("No books? Too bad.\n");

    puts("Bye.\n");
    fclose(pbooks);

    return 0;
}

char * s_gets(char * st, int n)
{
    char * ret_val;
    char *find;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');   // look for newline
        if (find)                  // if the address is not NULL,
            *find = '\0';          // place a null character there
        else    
            while (getchar() != '\n')
                continue;   // dispose of rest of line
    }
    return ret_val;
}

void eatline(void)
{
    while (getchar() != '\n')
        continue;
}

void modify_record(struct book * record)
{
    printf("Enter new title: ");
    s_gets(record->title, MAXTITL);
    printf("Enter the author: ");
    s_gets(record->author, MAXAUTL);
    printf("Enter the value: ");
    scanf("%f", &record->value);
    eatline();
}