#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


/*
* Goes through all the letters given by the user as input, shifting
* each letter by the shift given as an argument
*
* Thomas Komen, 12556963
*/
const int ALPHABET_LENGTH = 26;

int main(int argc, string argv[])
{
    //Gives an error if the user didn't provide 1 key
    if (argc != 2)
    {
        printf("Error: Not the right amount of arguments, please only use 1");
        return (1);
    }

    char *string = get_string("plaintext: ");
    int shift = atoi(argv[1]) % ALPHABET_LENGTH;
    int length = strlen(string);

    for (int i = 0; i < length; i++)
    {
        if (isalpha(string[i]))
        {
            // checks if the letter+shift > the relevant z, rotating back to a if so
            if ((string[i] <= 'Z' && string[i] + shift > 'Z') || (string[i] <= 'z' && string[i] + shift > 'z'))
            {
                string[i] = string[i] + shift - ALPHABET_LENGTH;
            }
            else
            {
                string[i] = string[i] + shift;
            }
        }
    }

    printf("ciphertext: %s\n", string);
}