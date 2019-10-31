#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int singlenumbers(long credit);
int doublednumbers(long credit);

int main(void)
{
    long credit = get_long("Give the credit number: ");
    int length = 1+log10(credit);
    int sum = singlenumbers(credit) + doublednumbers(credit/10);

    if(sum % 10 == 0)
    {
        while(log10(credit)>=2)
        {
            credit /= 10;
        }
        if(floor(credit/10) == 4 && (length == 13 || length == 16))
        {
            printf("VISA\n");
        }
        else if((credit == 51 || credit == 52 || credit == 53 || credit == 54 || credit == 55) && length == 16)
        {
            printf("MASTERCARD\n");
        }
        else if((credit == 34 || credit == 37) && length == 15)
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

int singlenumbers(long credit)
{
    int total = 0;
    while(credit>0)
    {
        int number = credit % 10;
        credit /= 100;
        total += number;
    }
    return(total);
}

int doublednumbers(long credit)
{
    int total = 0;
    while(credit>0)
    {
        int number = (credit % 10)*2;
        credit /= 100;
        if(log(number)>=1)
        {
            number = (number % 10) + (number / 10);
        }
        total += number;
    }
    return(total);
}