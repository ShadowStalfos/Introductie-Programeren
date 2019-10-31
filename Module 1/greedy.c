#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float famount = -1.00;
    while(!(famount>0))
    {
        famount = get_float("Enter an amount: ");
    }
    int amount = round(famount*100);
    int coins = 0;
    while(amount>=25)
    {
        amount -= 25;
        coins += 1;
    }
    while(amount>=10)
    {
        amount -= 10;
        coins += 1;
    }
    while(amount>=5)
    {
        amount -= 5;
        coins += 1;
    }
    while(amount>=1)
    {
        amount -= 1;
        coins += 1;
    }
    printf("%i\n", coins);
}