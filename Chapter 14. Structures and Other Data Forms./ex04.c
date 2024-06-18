// Write a program that creates a structure template with two members according to the
// following criteria:
// a. The first member is a social security number. The second member is a structure
// with three members. Its first member contains a first name, its second member
// contains a middle name, and its final member contains a last name. Create and
// initialize an array of five such structures. Have the program print the data in this
// format:
// Dribble, Flossie M. –– 302039823
// Only the initial letter of the middle name is printed, and a period is added. Neither the
// initial (of course) nor the period should be printed if the middle name member is empty.
// Write a function to do the printing; pass the structure array to the function.
// b. Modify part a. by passing the structure value instead of the address.

#include <stdio.h>
#define MAX_FNAME_LEN 100
#define MAX_MNAME_LEN 100
#define MAX_LNAME_LEN 100
#define ARRLEN 5


struct name {
    char fname[MAX_FNAME_LEN];
    char mname[MAX_MNAME_LEN];
    char lname[MAX_LNAME_LEN];
};

struct info {
    int soc_sec_num;
    struct name person_name;
};

void print_info(struct info * pinfo, int n);


int main(void)
{
    struct info people[ARRLEN] = 
    {
        { 123456789, { "Flossie", "Mister", "Dribble" } } ,
        { 987654321, { "Glossie", "The", "Durbin" }} ,
         {487674321, { "Nlossie", "Supermister", "Durvin"}} ,
         {453693046, { "Jossie", "", "Bibble" }} ,
        { 485390535, { "Fuflosie", "Soose", "Mibble"}} 
    };

    print_info(people, ARRLEN);

    return 0;
}

void print_info(struct info  pinfo[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if ((pinfo+i)->person_name.mname[0] == '\0')
        {
            printf("%s, %s -- %d\n", (pinfo+i)->person_name.fname, 
            (pinfo+i)->person_name.lname, (pinfo+i)->soc_sec_num);
        }
        else 
        {
            printf("%s, %s %c. -- %d\n", 
            (pinfo+i)->person_name.fname, (pinfo+i)->person_name.lname, 
            (pinfo+i)->person_name.mname[0], (pinfo+i)->soc_sec_num);
        }
    }
}