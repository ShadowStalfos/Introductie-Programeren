#include <cs50.h>
#include <stdio.h>
#include <math.h>
/*
*Asks the user for an amount of dollars, which it converts to pennies. It then
*checks for the biggest coin that fits in this amount. By doing this it eventually
*finds the minimum amount of coins needed for the given amount
*
*Thomas Komen, 12556963
*/
int main(void)
{
    float float_change;
    do
    {
        float_change = get_float("Change owed: ");
    }
    while (float_change < 0);

    //coverts the change from dollars to pennies
    int change = round(float_change * 100);
    int coins = 0;

    //goes through the available coins from largest to smallest, checking if
    //they fit in the remaining change, and removing the coin amount from the change
    //if it does
    while (change >= 25)
    {
        change -= 25;
        coins += 1;
    }
    while (change >= 10)
    {
        change -= 10;
        coins += 1;
    }
    while (change >= 5)
    {
        change -= 5;
        coins += 1;
    }
    while (change >= 1)
    {
        change -= 1;
        coins += 1;
    }

    printf("%i\n", coins);
}