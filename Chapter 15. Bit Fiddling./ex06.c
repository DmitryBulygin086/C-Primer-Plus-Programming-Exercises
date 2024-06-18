// Design a bit-field structure that holds the following information:
// 	  Font ID: A number in the range 0–255
// 	  Font Size: A number in the range 0–127
// 	  Alignment: A number in the range 0–2 represented the choices Left,
// 	    Center, and Right
//    Bold: Off (0) or on (1)
// 	  Italic: Off (0) or on (1)
// 	  Underline: Off (0) or on (1)
// Use this structure in a program that displays the font parameters and uses a
// looped menu to let the user change parameters. For example, a sample run
// might look like this:

// 	   ID SIZE ALIGNMENT  B   I   U 
//     1  12   left      off off off
    
//     f)change fonts	s)change size 	 a)change alignment
//     b)toggle bold 	i)toggle italic  u)toggle underline
// 	   q)quit
// 	   s
// 	   Enter font size (0-127): 36

// 	   ID SIZE ALIGNMENT  B   I   U 
//     1  36   left      off off off

//     f)change fonts	s)change size 	 a)change alignment
//     b)toggle bold 	i)toggle italic  u)toggle underline
// 	   q)quit
// 	   a
// 	   Select alignment:
// 	   l)left    c)center   r)right
// 	   r
// 	   ...

#include <stdio.h>
#include <stdbool.h>
#define LEFT 0
#define CENTER 1
#define RIGHT 2
#define OFF 0
#define ON 1

// Design a bit-field structure that holds the following information:

typedef struct  {
    unsigned char font_id : 8;
    unsigned char font_size : 7;
    unsigned char            : 1;
    unsigned char alignment : 2;
    bool bold  : 1;
    bool italic : 1;
    bool underline : 1;
} Font;

void eatline(void) { while (getchar() != '\n') continue;}

void print_menu(Font *);

void set_font_id(Font *);

void set_font_size(Font *);

void set_alignment(Font *);


int main(void)
{
    Font font = {1, 12, 0, 0, 0, 0};
    char choice;
    bool quit = false;
   
    while (1)
    {
        print_menu(&font);
        choice = getchar();
        eatline();

        switch(choice)
        {
            case 'f':
                set_font_id(&font);
                break;
            case 's' :
                set_font_size(&font);
                break;
            case 'a' :
                set_alignment(&font);
                break;
            case'b':
                font.bold ^= 1;
                break;
            case 'i':
                font.italic ^= 1;
                break;
            case 'u':
                font.underline ^= 1;
                break;
            case 'q' :
                quit = true;
                break;
            default: 
                fprintf(stderr, "Invalid choice\n");
                continue;
        }   
        if (quit)
            break;
    }      
}

void set_font_id(Font * font)
{
    unsigned char font_ind;
    printf("Enter font ID (0-255): ");
    while (scanf("%hhu", &font_ind) != 1)
    {
        eatline();
        fprintf(stderr, "Enter font ID (0-255): ");
    }
    eatline();
    font->font_id = font_ind;
}

void set_font_size (Font * font)
{
    unsigned char font_size;
    printf("Enter font size (0-127): ");
    while (scanf("%hhu", &font_size) != 1)
    {
        eatline();
        fprintf(stderr, "Enter font size (0-127): ");
    }
    eatline();

    font->font_size = font_size;
}

void set_alignment(Font  *font)
{
    char choice;
    unsigned char alignment;
    while (1)
    {
        printf("Select alignment:\n");
        printf("l)left    c)center   r)right\n");
        choice = getchar();
        eatline();
        switch(choice)
        {
            case 'l':
                alignment = LEFT;
                break;
            case 'c':
                alignment = CENTER;
                break;
            case 'r':
                alignment = RIGHT;
                break;
            default:
                fprintf(stderr, "Enter l, c, or r.\n");
                continue;
        }
        break;
    }
    font->alignment = alignment;
}

void print_menu(Font *font)
{
    char *alignment;
   switch(font->alignment)
   {
        case LEFT: alignment = "left"; break;
        case CENTER: alignment = "center"; break;
        case RIGHT: alignment = "right"; break;
        default:
            fprintf(stderr, "Invalid alignment");
            break;
   }
    printf("ID SIZE ALIGNMENT  B   I   U \n");
    printf("%d  %d   %s      %s   %s  %s\n\n", font->font_id, font->font_size, alignment, font->bold ? "on" : "off", font->italic ? "on" : "off", font->underline ? "on" : "off");
    printf("f)change fonts    s)change size      a)change alignment\n");
    printf("b)toggle bold     i)toggle italic  u)toggle underline\n");
    printf("q)quit\n");
}
