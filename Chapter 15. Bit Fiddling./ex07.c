// Write a program with the same behavior as described in exercise 6, but use an unsigned
// long variable to hold the font information and use the bitwise operators instead of bit
// members to manage the information.


#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define LEFT 0
#define CENTER 1
#define RIGHT 2

#define ON 1
#define OFF 0
char *onoff(bool status)
{
    if (status)
    {
        return "on";
    }
    else 
        return "off";
}


#define ID_SHIFT 0x0
#define SIZE_SHIFT (ID_SHIFT + 0x8)
#define ALIGN_SHIFT (SIZE_SHIFT + 0x7)
#define BOLD_SHIFT (ALIGN_SHIFT + 0x3)
#define ITAL_SHIFT (BOLD_SHIFT + 0x1)
#define UNDERL_SHIFT (ITAL_SHIFT + 0x1)




#define ID_MASK (0xFF << ID_SHIFT)
#define SIZE_MASK (0x7F << SIZE_SHIFT)
#define ALIGN_MASK (0x3 << ALIGN_SHIFT)
#define BOLD_MASK (0x1 << BOLD_SHIFT)
#define ITAL_MASK (0x1 << ITAL_SHIFT)
#define UNDERL_MASK (0x1 << UNDERL_SHIFT)







unsigned int return_id(unsigned int font) 
{
    return (font & ID_MASK) >> ID_SHIFT;
}

unsigned int return_size(unsigned int font)
{
    return (font & SIZE_MASK) >> SIZE_SHIFT;
}

unsigned int return_align(unsigned int font)
{
    return (font & ALIGN_MASK) >> ALIGN_SHIFT;
}

char *return_align_string(unsigned int font)
{
    switch (return_align(font))
    {
        case LEFT:
            return "left";
        case CENTER:
            return "center";
        case RIGHT:
            return "right";
        default:
            return "error";
    }
}

bool return_bold(unsigned int font)
{
    return (font & BOLD_MASK) >> BOLD_SHIFT;
}

bool return_ital(unsigned int font)
{
    return (font & ITAL_MASK) >> ITAL_SHIFT;
}

bool return_underl(unsigned int font)
{
    return (font & UNDERL_MASK) >> UNDERL_SHIFT;
}



void set_id(unsigned int *font, unsigned int id)
{
    *font = (*font & ~ID_MASK);
    *font |= ((id << ID_SHIFT) & ID_MASK);
}

void set_size(unsigned int *font, unsigned int size) 
{
    *font = (*font & ~SIZE_MASK);
    *font |= ((size << SIZE_SHIFT) & SIZE_MASK);
}

void set_align(unsigned int *font, unsigned int align)
{
    *font &= ~ALIGN_MASK;
    *font |= ((align << ALIGN_SHIFT) & ALIGN_MASK);
}



void toggle_bold(unsigned int *font)
{
    *font ^= BOLD_MASK;
}

void toggle_ital(unsigned int *font)
{
    *font ^= ITAL_MASK;
}

void toggle_underl(unsigned int *font)
{
    *font ^= UNDERL_MASK;
}

void eatline(void)
{
    while(getchar()!= '\n')
        continue;
}


typedef unsigned int Font;

void display_font(unsigned int font);

void print_menu(void);

void setid(unsigned int *font);

void setsize(unsigned int * font);

void setalign(unsigned int *font);

int main(void)
{
    Font font = 0;
    set_id(&font, 1);
    set_size(&font, 12);
    set_align(&font, LEFT);
    

    
    char choice;
    while (1)
    {
        display_font(font);
        putchar('\n');
        print_menu();
        choice = getchar();
        eatline();
        switch(choice)
        {
            case 'f' :
            {
                setid(&font);
                break;
            }
            case 's' :
            {
                setsize(&font);
                break;
            }
            case 'a' :
            {
                setalign(&font);
                break;
            }
            case 'b' :
            {
                toggle_bold(&font);
                break;     
            }
            case 'i' :
            {
                toggle_ital(&font);
                break;
            }
            case 'u' :
            {
                toggle_underl(&font);
                break;
            }
            case 'q' :
            {
                exit(EXIT_SUCCESS);
            }
            default :
            {
                fprintf(stderr,"Invalid choice.\n");
                continue;
            }
        }
    }
}

void display_font(unsigned int font)
{
    printf("ID SIZE ALIGNMENT  B   I   U \n");
    printf("%d  %d   %s      %s   %s  %s\n", return_id(font), return_size(font), return_align_string(font), 
            onoff(return_bold(font)), onoff(return_ital(font)), onoff(return_underl(font)));
}

void print_menu(void)
{
    printf("f)change fonts    s)change size      a)change alignment\n");
    printf("b)toggle bold     i)toggle italic  u)toggle underline\n");
    printf("q)quit\n");
}

void setid(unsigned int *font)
{
    unsigned int id;
    printf("Enter ID: ");
    while (scanf("%u", &id) != 1)
    {
        eatline();
        printf("Invalid input. Try again: ");
    }
    eatline();
    set_id(font, id);
}

void setsize(unsigned int *font)
{
    unsigned int size;
    printf("Enter size: ");
    while (scanf("%u", &size)!= 1)
    {
        eatline();
        printf("Invalid input. Try again: ");
    }
    eatline();
    set_size(font, size);
}

void setalign(unsigned int *font)
{
    char ch;
    printf("Select alignment: \n");
    puts("l) left  c) center  r) right");

    while (!((ch = getchar()) == 'l' || ch == 'c' || ch == 'r'))
    {
        eatline();
        fprintf(stderr, "Invalid input. Try again: ");
    }
    eatline();

    switch (ch)
    {
        case 'l':
            set_align(font, LEFT);
            break;
        case 'c':
            set_align(font, CENTER);
            break;
        case 'r':
            set_align(font, RIGHT);
            break;
        default:
            break;
    }
}
