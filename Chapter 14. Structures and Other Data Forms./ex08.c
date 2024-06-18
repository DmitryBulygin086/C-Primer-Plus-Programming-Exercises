// The Colossus Airlines fleet consists of one plane with a seating capacity of 12. It makes
// one flight daily. Write a seating reservation program with the following features:
// a. The program uses an array of 12 structures. Each structure should hold a seat
// identification number, a marker that indicates whether the seat is assigned, the last
// name of the seat holder, and the first name of the seat holder.
// b. The program displays the following menu:
// To choose a function, enter its letter label:
// a) Show number of empty seats
// b) Show list of empty seats
// c) Show alphabetical list of seats
// d) Assign a customer to a seat assignment
// e) Delete a seat assignment
// f) Quit
// c. The program successfully executes the promises of its menu. Choices d) and e)
// require additional input, and each should enable the user to abort an entry.
// d. After executing a particular function, the program shows the menu again, except
// for choice f).
// e. Data is saved in a file between runs. When the program is restarted, it first loads in
// the data, if any, from the file.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX_SEATS 12
#define NAMELEN 20

struct seat_info {
    int seat_id;
    bool assigned;
    char lname[NAMELEN];
    char fname[NAMELEN];
};

struct seat_info seats[MAX_SEATS];

void eatline(void);

void show_number_of_empty_seats(int max_seats, struct seat_info seats[max_seats]);
void show_list_of_empty_seats(int max_seats, struct seat_info seats[max_seats]);

void show_alphabetical_list_of_seats(int max_seats, struct seat_info seats[max_seats]);

void assign_a_customer(int max_seats, struct seat_info seats[max_seats]);

void delete_a_seat_assignment(int max_seats, struct seat_info seats[max_seats]);

char * s_gets(char * st, int n);
int main(void)
{
    struct seat_info tmp;
    FILE *fp;
    
    for (int i = 0; i < MAX_SEATS; i++)
    {
        seats[i] = (struct seat_info) {i, false, "", ""};
    }

    fp = fopen("seats.txt", "rb");
    if (fp == NULL)
    {
        fprintf(stderr, "Could not open file.\n");
        exit(EXIT_FAILURE);
    }

    while (fread(&tmp, sizeof(struct seat_info), 1, fp) == 1)
    {   
        seats[tmp.seat_id] = tmp;
    }
   

    char choice;
    bool quit = false;

    printf("Welcome to Colossus Airlines!\n");
    while (1)
    {
        printf("To choose a function, enter its letter label:\n");
        printf("a) Show number of empty seats\n");
        printf("b) Show list of empty seats\n");
        printf("c) Show alphabetical list of seats\n");
        printf("d) Assign a customer to a seat assignment\n");
        printf("e) Delete a seat assignment\n");
        printf("f) Quit\n");

        choice = getchar();
        eatline();

        switch(choice)
        {
            case 'a' :
                show_number_of_empty_seats(MAX_SEATS,seats);
                break;
            case 'b' :
                show_list_of_empty_seats(MAX_SEATS, seats);
                break;
            case 'c' :
                show_alphabetical_list_of_seats(MAX_SEATS,seats);
                break;
            case 'd' :
                assign_a_customer(MAX_SEATS,seats);
                break;
            case 'e' :
                delete_a_seat_assignment(MAX_SEATS,seats);
                break;
            case 'f' :
                quit = true;
                break;
            default :
                fprintf(stderr, "Invalid choice.\n");
                printf("Please try again.\n");
                break;
        }
        if (quit)
            break;
    }

    if (fclose(fp) != 0)
    {
        fprintf(stderr, "Could not close file.\n");
        exit(EXIT_FAILURE);
    }

    fp = fopen("seats.txt", "wb");
    if (fp == NULL)
    {
        fprintf(stderr, "Could not open file for writing.\n");
        exit(EXIT_FAILURE);
    }

    if (fwrite(seats, sizeof(struct seat_info), MAX_SEATS, fp) != MAX_SEATS)
    {
        fprintf(stderr, "Error in writing to file.\n");
        exit(EXIT_FAILURE);
    }

    if (fclose(fp) != 0)
    {
        fprintf(stderr, "Could not close file.\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}

void eatline(void)
{
    while (getchar() != '\n')
        continue;
}

void show_number_of_empty_seats(int max_seats,struct seat_info seats[max_seats])
{
    int empty_seats = 0;
    for (int i = 0; i < max_seats; i++)
    {
        if (seats[i].assigned == false)
        {
            empty_seats++;
        }
    }

    printf("There are %d empty seats.\n", empty_seats);
}

void show_list_of_empty_seats(int max_seats,struct seat_info seats[max_seats])
{
    printf("Here is a list of empty seats:\n");
    for (int i = 0; i < max_seats; i++)
    {
        if (seats[i].assigned == false)
        {
            printf("%d\n", seats[i].seat_id);
        }
    }
}

void show_alphabetical_list_of_seats(int max_seats,struct seat_info seats[max_seats])
{   
    printf("Here is an alphabetical list of seats:\n");
    printf("\n%20s %20s %5s\n", "Last Name", "First Name", "Seat ID");
    for (int i = 0; i < max_seats; i++)
    {
        if (seats[i].assigned == true)
            printf("%20s %20s %5d\n", (seats+i)->lname, (seats+i)->fname, (seats+i)->seat_id);
    }
    
}

void assign_a_customer(int max_seats,struct seat_info seats[max_seats])
{
    int seat_indent;
    char lname[NAMELEN];
    char fname[NAMELEN];
    
    while (1)
    {
        printf("Enter the seat number:\n");
        while(scanf("%d", &seat_indent) != 1 || seat_indent < 0 || seat_indent > max_seats - 1)
        {
            eatline();
            fprintf(stderr, "Please enter an integer from 0 to %d.\n", max_seats - 1);
            printf("Enter the seat number:\n");
        }
        eatline();

        if (seats[seat_indent].assigned == true)
        {
            printf("Seat %d is already assigned.\nTry again.\n", seat_indent);
            continue;
        }

        printf("Enter the last name:\n");
        s_gets(lname, NAMELEN);

        printf("Enter the first name:\n");
        s_gets(fname, NAMELEN);

        for (int i = 0; i < max_seats; i++)
        {
            if ((seats+i)->seat_id == seat_indent && (seats+i)->assigned == false)
            {
                (seats+i)->assigned = true;
                strcpy((seats+i)->lname, lname);
                strcpy((seats+i)->fname, fname);
              
            }
        }
     
        break;
    }
}

void delete_a_seat_assignment(int max_seats,struct seat_info seats[max_seats])
{
    int seat_indent;
    char choice;
    while (1)
    {
        printf("Enter the seat id from which you wish to delete assignment(nonnumeric input or <0 or >%d to quit):\n", max_seats - 1);
        if((scanf("%d", &seat_indent)) != 1 || seat_indent < 0 || seat_indent > max_seats - 1)
        {
            eatline();
            fprintf(stderr, "Please enter an integer from 0 to %d.\n", max_seats);
            continue;
        }
        eatline();

        puts("Here is the seat assignment you wish to delete:\n");
        printf("Seat ID: %d First name: %s Last name: %s\n", seats[seat_indent].seat_id, seats[seat_indent].fname, seats[seat_indent].lname);
        printf("Do you want to delete this assignment(y or n)?\n");
        choice = getchar();
        eatline();

        if (choice == 'y' || choice == 'Y')
        {
            (seats+seat_indent)->assigned = false;
            (seats+seat_indent)->lname[0] = '\0';
            (seats+seat_indent)->fname[0] = '\0';
        }
        else 
        {
            printf("The seat assignment was not deleted.\n");
        }
        break;
    }
}

char * s_gets(char * st, int n)
{
    char * ret_val;
    char * find;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar()!= '\n')
                continue;
    }
    return ret_val;
}