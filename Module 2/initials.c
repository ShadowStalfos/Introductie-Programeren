#include <cs50.h>
#include <stdio.h>
#include <string.h>

/*
* Tries to find the initials of a given name
* Prints the first letter of the name, and every character after a space
*
* Thomas Komen, 12556963
*/
char lower_to_upper(char letter);

int main(void)
{
    char *name = get_string("Give Name: ");
    int length = strlen(name);
    int j = 0;

    // Skips the spaces in front of the name and prints the first letter
    while (name[j] == ' ')
    {
        j++;
    }
    printf("%c", lower_to_upper(name[j]));

    //Tries to find a space followed by a letter, and prints the letter
    for (int i = j; i < length - 1; i++)
    {
        if (name[i] == ' ' && isalpha(name[i + 1]))
        {
            printf("%c", lower_to_upper(name[i + 1]));
        }
    }
    printf("\n");
}

//If the letter is lowercase, make it uppercase
char lower_to_upper(char letter)
{
    if (letter >= 'a')
    {
        return (letter - 32);
    }
    else
    {
        return (letter);
    }
}
