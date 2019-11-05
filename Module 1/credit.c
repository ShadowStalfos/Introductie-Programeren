#include <stdio.h>
#include <cs50.h>
#include <math.h>
/*
*Uses Luhn's algorithm to check if a given creditcard number is valid
*and if it is, checks what kind of creditcard it is
*
*Thomas Komen, 12556963
*/
int singlenumbers(long credit);
int doublednumbers(long credit);

int main(void)
{
    long credit = get_long("Give a creditcard number: ");
    int length = 1 + log10(credit);

    //Checks if the last digit of the sum from Luhn's algorithm equals 0
    int sum = singlenumbers(credit) + doublednumbers(credit / 10);
    if (sum % 10 == 0)
    {
        while (log10(credit) >= 2)
        {
            credit /= 10;
        }

        //Checks all the specified properties of certain creditcards, to find
        //what kind of card it is
        if (floor(credit / 10) == 4 && (length == 13 || length == 16))
        {
            printf("VISA\n");
        }
        else if ((credit >= 51 && credit <= 55) && length == 16)
        {
            printf("MASTERCARD\n");
        }
        else if ((credit == 34 || credit == 37) && length == 15)
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

//Goes through a number, and adds digits to a total,
//starting at the end, and skipping every other number
int singlenumbers(long credit)
{
    int total = 0;
    while (credit > 0)
    {
        int number = credit % 10;
        credit /= 100;
        total += number;
    }
    return (total);
}

//Goes through a number, and adds double the digits to a total, starting at the
//end, and skipping every other number. If the double exceeds 10, splits that double
//and adds the seperate digits to the total.
int doublednumbers(long credit)
{
    int total = 0;
    while (credit > 0)
    {
        int number = (credit % 10) * 2;
        credit /= 100;
        if (log(number) >= 1)
        {
            number = (number % 10) + (number / 10);
        }
        total += number;
    }
    return (total);
}