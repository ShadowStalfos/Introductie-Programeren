#include <cs50.h>
#include <stdio.h>
/*
*Prints the left half of a pyramid with a given height on the screen
*
*Thomas Komen, 12556963
*/
int main(void)
{
    int height;
    do
    {
        height = get_int("Give a height: ");
    }
    while ((height < 0) || (height > 23));

    //For a given heigth, goes through each line to print the amount of needed
    //hashtags, with the appropriate amount of spaces in front of it to line
    //the hastags up to the right
    for (int i = 1; i <= height; i++)
    {
        for (int x = 0; x < (height - i); x++)
        {
            printf(" ");
        }
        for (int x = 0; x < (i + 1); x++)
        {
            printf("#");
        }
        printf("\n");
    }
}