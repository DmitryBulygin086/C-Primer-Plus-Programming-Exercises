// Write and test in a loop a function that returns the number of times it has been called.

#include <stdio.h>



int loop_ct_func(void);
int main(void)
{
   
    for (int count = 0; count < 4; count++)
    {
        printf("loop_ct_func() returns %d\n", loop_ct_func());
    }
    
    return 0;
}

int loop_ct_func(void)
{
    static int loop_ct;
    return ++loop_ct;
}