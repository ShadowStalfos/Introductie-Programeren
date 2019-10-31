#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int i, x;
    int height = -1;
    while((height<0) || (height>23))
    {
        height = get_int("Give a height: ");
    }
    for(i=1; i<=height; i++)
    {
        for(x=0; x<(height-i); x++)
        {
            printf(" ");
        }
        for(x=0; x<(i+1); x++)
        {
            printf("#");
        }
        printf("\n");
    }
}