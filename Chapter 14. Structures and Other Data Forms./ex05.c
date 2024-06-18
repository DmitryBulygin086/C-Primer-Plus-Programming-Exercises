// Write a program that fits the following recipe:
// a. Externally define a name structure template with two members: a string to hold the
// first name and a string to hold the second name.
// b. Externally define a student structure template with three members: a name
// structure, a grade array to hold three floating-point scores, and a variable to hold
// the average of those three scores.
// c. Have the main() function declare an array of CSIZE (with CSIZE = 4) student
// structures and initialize the name portions to names of your choice. Use functions
// to perform the tasks described in parts d., e., f., and g.
// d. Interactively acquire scores for each student by prompting the user with a student
// name and a request for scores. Place the scores in the grade array portion of the
// appropriate structure. The required looping can be done in main() or in the
// function, as you prefer.
// e. Calculate the average score value for each structure and assign it to the proper
// member.
// f. Print the information in each structure.
// g. Print the class average for each of the numeric structure members.

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define NAMELEN 20
#define CSIZE 4

struct name {
    char fname[NAMELEN];
    char lname[NAMELEN];
};

struct student {
    struct name st_name;
    float scores[3];
    float avg;
};

void eatline(void);
void get_grades(struct student *, int csize);

void calculate_avgs(struct student *, int csize);

void print_students_info(struct student *, int csize);

void print_class_average(struct student *, int csize);

int main(void)
{
    char student_fname[NAMELEN];
    char student_lname[NAMELEN];
    int input_ct = 0;

    struct student students[CSIZE] = {
       {.st_name =  {"John", "Doe"}},
        {.st_name = {"Jane", "Due"}},
        {.st_name = {"Jack", "Dude"}},
        {.st_name = {"Jill", "Durde"}}
    };

    get_grades(students, CSIZE);

    calculate_avgs(students, CSIZE);

    print_students_info(students, CSIZE);

    print_class_average(students, CSIZE);

    return 0;
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
}

void eatline(void)
{
    while (getchar() != '\n')
    {
        continue;
    }
}

void get_grades(struct student * st, int csize)
{
    int input_ct = 0;
    char student_fname[NAMELEN];
    char student_lname[NAMELEN];
    bool found = false;

    while (1)
    {
        found = false;
        printf("Enter first name of student: ");
        s_gets(student_fname, NAMELEN);
        printf("Enter last name of student: ");
        s_gets(student_lname, NAMELEN);

        for (int index = 0; index < CSIZE; index++)
        {
            if (strcmp(student_fname, (st+index)->st_name.fname) == 0 && 
            strcmp(student_lname, (st+index)->st_name.lname) == 0)
            {
                input_ct++;
                found = true;
                printf("Enter score 1 for %s %s: ", student_fname, student_lname);
                while (scanf("%f", &(st+index)->scores[0]) != 1)
                {
                    eatline();
                    fprintf(stderr, "Invalid input. Try again.\n");
                    printf("Enter score 1 for %s %s: ", student_fname, student_lname);
                }
                eatline();

                printf("Enter score 2 for %s %s: ", student_fname, student_lname);
                while (scanf("%f", &(st+index)->scores[1]) != 1)
                {
                    eatline();
                    fprintf(stderr, "Invalid input. Try again.\n");
                    printf("Enter score 2 for %s %s: ", student_fname, student_lname);
                }
                eatline();

                printf("Enter score 3 for %s %s: ", student_fname, student_lname);
                while (scanf("%f", &(st+index)->scores[2]) != 1)
                {
                    eatline();
                    fprintf(stderr, "Invalid input. Try again.\n");
                    printf("Enter score 3 for %s %s: ", student_fname, student_lname);
                }
                eatline();
            }

            if (found)
                break;
        
        }
        if (input_ct == CSIZE)
            break;
    }
    
}

void calculate_avgs(struct student * students, int csize)
{
    for (int index = 0; index < csize ; index++)
    {
        (students+index)->avg = ((students+index)->scores[0] + (students+index)->scores[1] + (students+index)->scores[2]) / 3;
    }
}

void print_students_info(struct student * students, int csize)
{
    for (int index = 0; index < csize; index++)
    {
        printf("%s %s\n", (students+index)->st_name.fname, (students+index)->st_name.lname);
        printf("Score 1: %.2f\n", (students+index)->scores[0]);
        printf("Score 2: %.2f\n", (students+index)->scores[1]);
        printf("Score 3: %.2f\n", (students+index)->scores[2]);
        printf("Average: %.2f\n", (students+index)->avg);
    }
}

void print_class_average(struct student * students, int csize)
{
    float class_avg = 0;
    for (int index = 0; index < csize; index++)
    {
        class_avg += (students+index)->avg;
    }
    class_avg /= csize;
    printf("Class average: %.2f\n", class_avg);
}