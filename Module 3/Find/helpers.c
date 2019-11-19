// Helper functions

#include <cs50.h>
#include <math.h>
#include <stdio.h>
#define MAX 65536

#include "helpers.h"

// Maximum amount of hay
//const int MAX = 65536;

// Returns true if value is in array of n values, else false
bool search(int value, int values[], int n)
{
    if (n < 1)
    {
        return (false);
    }

    int lower = 0;
    int upper = n - 1;

    if (values[0] == value || values[n - 1] == value)
    {
        return true;
    }
    //Changes the lower and upper bound according to the value of the middle
    //until the middle either is the given needle, or all values have been searched
    while (!(lower + 1 == upper))
    {
        int middle = floor((lower + upper) / 2);
        if (values[middle] == value)
        {
            return (true);
        }
        else if (values[middle] < value)
        {
            lower = middle;
        }
        else if (values[middle] > value)
        {
            upper = middle;
        }
    }
    return false;
}

// Sorts array of n values
void sort(int values[], int n)
{
    int sortinglist[MAX] = {0};

    // Increases the value of the number in the sorting list with index number by 1
    for (int i = 0; i < n; i++)
    {
        int number = values[i];
        sortinglist[number]++;
    }
    int index = 0;

    // Goes through sorting list and puts the value of an index in a list an amount of
    // times equal to the value of sortinglist[index]
    for (int j = 0; j < MAX; j++)
    {
        while (sortinglist[j] > 0)
        {
            values[index] = j;
            index++;
            sortinglist[j] -= 1;
        }
    }
    return;
}
