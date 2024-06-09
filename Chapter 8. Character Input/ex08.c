// Write a program that shows you a menu offering you the choice of addition, subtraction,
// multiplication, or division. After getting your choice, the program asks for two numbers,
// then performs the requested operation. The program should accept only the offered
// menu choices. It should use type float for the numbers and allow the user to try again
// if he or she fails to enter a number. In the case of division, the program should prompt
// the user to enter a new value if 0 is entered as the value for the second number. A typical
// program run should look like this:
// Enter the operation of your choice:
// a. add
// s. subtract
// m. multiply
// d. divide
// q. quit
// a
// Enter first number: 22.4
// Enter second number: one
// one is not an number.
// Please enter a number, such as 2.5, -1.78E8, or 3: 1
// 22.4 + 1 = 23.4
// Enter the operation of your choice:
// a. add
// s. subtract
// m. multiply
// d. divide
// q. quit
// d
// Enter first number: 18.4
// Enter second number: 0
// Enter a number other than 0: 0.2
// 18.4 / 0.2 = 92
// Enter the operation of your choice:
// a. add
// s. subtract
// m. multiply
// d. divide
// q. quit
// q
// Bye.

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
void print_choices(void);
void flush_input_buffer(void);
char get_first(void);
int main(void)
{
    bool exit_flag = false;
    while (1)
    {
        // Get operation
        char choice;
        print_choices();
        choice = get_first();
        switch(choice)
        {
            case 'q' :
                exit_flag = true;
                break;
            case 'a' :
                break;
            case 's' :
                break;
            case 'm' :
                break;
            case 'd' :
                break;
            default :
                printf("Invalid input. Try again.\n");
                continue;
        }
        if (exit_flag)
        {
            break;
        }

        // Get numbers
        float num1, num2;
        char ch;
        printf("Enter first number: ");
        while((scanf("%f", &num1)) != 1)
        {
            while ((ch = getchar()) != '\n')
                putchar(ch);
            printf(" is not a number.\n");
            printf("Please enter a number, such as 2.5, -1.78E8, or 3: ");
        }
        printf("Enter second number: ");
        while(((scanf("%f", &num2)) != 1) || (choice == 'd') && (num2 == 0))
        {
            // Handle 0 as a second number if dividing is choosen
            if ((choice == 'd') && (num2 == 0))
            {
                flush_input_buffer();
                printf("Enter a number other than 0: ");
                continue;
            }
            while ((ch = getchar()) != '\n')
                putchar(ch);
            printf(" is not a number.\n");
            printf("Please enter a number, such as 2.5, -1.78E8, or 3: ");
        }
        

        // Do operation on numbers
        
        float result;
        switch(choice)
        {
            case 'q' :
                exit_flag = true;
                break;
            case 'a' :
                result = num1 + num2;
                printf("result = %f\n", result);
                break;
            case 's' :
                result = num1 - num2;
                printf("result = %f\n", result);
                break;
            case 'm' :
                result = num1 * num2;
                printf("result = %f\n", result);
                break;
            case 'd' :
                result = num1 / num2;
                printf("result = %f\n", result);
                break;
            default :
                continue;
            
        }
        if (exit_flag)
        {
            break;
        }

    }
    return 0;
}

void print_choices(void)
{
    puts("Enter the operation of your choice:");
    puts("a. add");
    puts("s. subtract");
    puts("m. multiply");
    puts("d. divide");
    puts("q. quit");
}

char get_first(void)
{
    char ch, garbage;
    do 
    {
        ch = getchar();
    }
    while (isspace(ch));

    while ((garbage = getchar()) != '\n' && garbage != EOF)
        continue;
    
    return ch;
}

void flush_input_buffer(void)
{
    while (getchar() != '\n')
        continue;
}