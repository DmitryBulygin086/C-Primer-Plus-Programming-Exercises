#include "bin_search.h"

static int binsearch_helper(int arr[], int target, int low, int high);
bool inArr(int arr[], int arr_size, int target) 
{
    return binsearch_helper(arr, target, 0, arr_size - 1);
}

static int binsearch_helper(int arr[], int target, int low, int high)
{
    if (low == high)
        return arr[low] == target ? 1 : 0;

    else 
    {
        int mid = (low + high) / 2;
        if (arr[mid] < target)
            return binsearch_helper(arr, target, mid + 1, high);
        else 
            return binsearch_helper(arr, target, low, mid);
    }
}