#include <stdlib.h>
#include <stdio.h>
int * make_array(int elem, int val)
{
    int *arr;
    arr = (int *)malloc(sizeof(val) * elem);
    
    if(arr != NULL)
    {
        for(int i = 0; i < elem; i++)
        {
            arr[i] = val;
        }
    }
    
    return arr;
}

void show_array(const int ar[], int n)
{
    unsigned ct = 0;
    for (unsigned i = 0; i < n; i++)
    {
        printf("%6d", ar[i]);
        ct++;
        if (ct % 9 == 8)
        {
            putchar('\n');
        }
    }
    if (ct % 9 != 8)
        putchar('\n');
}