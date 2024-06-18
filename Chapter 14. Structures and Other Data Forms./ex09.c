// Colossus Airlines (from exercise 8) acquires a second plane (same capacity) and expands
// its service to four flights daily (Flights 102, 311, 444, and 519). Expand the program to
// handle four flights. Have a top-level menu that offers a choice of flights and the option
// to quit. Selecting a particular flight should then bring up a menu similar to that of
// exercise 8. However, one new item should be added: confirming a seat assignment. Also,
// the quit choice should be replaced with the choice of exiting to the top-level menu. Each
// display should indicate which flight is currently being handled. Also, the seat assignment
// display should indicate the confirmation status.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX_SEATS 12
#define FLIGHTS 4
#define NAMELEN 20

struct seat_info {
    int seat_id;
    bool assigned;
    char lname[NAMELEN];
    char fname[NAMELEN];
};

struct flight_info {
    int flight_id;
    struct seat_info seats[MAX_SEATS];
};

struct flight_info flights[FLIGHTS] = {
    {.flight_id = 102, {}},
    {.flight_id = 311, {}},
    {.flight_id = 444, {}},
    {.flight_id = 519, {}}
};

void eatline(void);

void show_number_of_empty_seats(int max_seats, struct seat_info seats[max_seats]);
void show_list_of_empty_seats(int max_seats, struct seat_info seats[max_seats]);

void show_alphabetical_list_of_seats(int max_seats, struct seat_info seats[max_seats]);

void assign_a_customer(int max_seats, struct seat_info seats[max_seats]);

void delete_a_seat_assignment(int max_seats, struct seat_info seats[max_seats]);

char * s_gets(char * st, int n);

void print_menu(void);

void print_flight_menu(void);

int main(void)
{
    struct flight_info tmp;
    FILE *fp;
    struct flight_info * flightp;
    char choice;
    bool quit = false;
    bool quit_to_top = false;

    for (int i = 0; i < FLIGHTS; i++)
    {
        for (int j = 0; j < MAX_SEATS; j++)
        {
            flights[i].seats[j] = (struct seat_info) {j, false, "", ""};
        }
    }

    fp = fopen("Colossus.dat", "rb");
    if (fp == NULL)
    {
        fprintf(stderr, "Could not open file.\n");
        exit(EXIT_FAILURE);
    }

    
    while (fread(&tmp, sizeof(struct flight_info), 1, fp) == 1)
    {   
        int flight_number = tmp.flight_id;
        for (int i = 0; i < FLIGHTS; i++)
        {
            if (flight_number == flights[i].flight_id)
            {
                flights[i] = tmp;
                break;
            }
        }
    }
   

    

    printf("Welcome to Colossus Airlines!\n");
    while (1)
    {

        print_flight_menu();
        choice = getchar();
        eatline();
        switch(choice)
        {
            case '1' :
                flightp = &flights[0];
                break;
            case '2' :
                flightp = &flights[1];
                break;
            case '3' :
                flightp = &flights[2];
                break;
            case '4' :
                flightp = &flights[3];
                break;
            case '5' :
                quit = true;
                break;
            default :
                fprintf(stderr, "Invalid choice.\n");
                printf("Please try again.\n");
                continue;
        }
        if (quit)
        {
            break;
        }


        while (1)
        {
            quit_to_top = false;
            print_menu();
            choice = getchar();
            eatline();

            switch(choice)
            {
                case 'a' :
                    show_number_of_empty_seats(MAX_SEATS,flightp->seats);
                    break;
                case 'b' :
                    show_list_of_empty_seats(MAX_SEATS, flightp->seats);
                    break;
                case 'c' :
                    show_alphabetical_list_of_seats(MAX_SEATS,flightp->seats);
                    break;
                case 'd' :
                    assign_a_customer(MAX_SEATS,flightp->seats);
                    break;
                case 'e' :
                    delete_a_seat_assignment(MAX_SEATS,flightp->seats);
                    break;
                case 'f' :
                {
                    quit_to_top = true;
                    break;
                }
                default :
                    fprintf(stderr, "Invalid choice.\n");
                    printf("Please try again.\n");
                    break;
            }
            if (quit_to_top)
                break;
        }
    }

    if (fclose(fp) != 0)
    {
        fprintf(stderr, "Could not close file.\n");
        exit(EXIT_FAILURE);
    }

    fp = fopen("Colossus.dat", "wb");
    if (fp == NULL)
    {
        fprintf(stderr, "Could not open file for writing.\n");
        exit(EXIT_FAILURE);
    }

    if (fwrite(&flights[0], sizeof(struct flight_info), FLIGHTS, fp) != FLIGHTS)
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

void print_menu(void)
{
    printf("To choose a function, enter its letter label:\n");
    printf("a) Show number of empty seats\n");
    printf("b) Show list of empty seats\n");
    printf("c) Show alphabetical list of seats\n");
    printf("d) Assign a customer to a seat assignment\n");
    printf("e) Delete a seat assignment\n");
    printf("f) Quit to top level menu\n");

}

void print_flight_menu(void)
{
    printf("Enter the number which is corresponds to flight number:\n");
    printf("1) 102\n");
    printf("2) 311\n");
    printf("3) 444\n");
    printf("4) 519\n");
    printf("5) Quit\n");
}