#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Nope, that ain't it chief");
        return(1);
    }
    char* string = get_string("plaintext: ");
    int shift = atoi(argv[1]) % 26;
    int length = strlen(string);
    for (int i = 0; i < length; i++)
    {
        if(isalpha(string[i]))
        {
            if((string[i] <= 'Z' && string[i] + shift > 'Z') || (string[i] <= 'z' && string[i] + shift > 'z'))
            {
                string[i] = string[i]+shift-26;
            }
            else
            {
                string[i] = string[i]+shift;
            }


        }
    }
    printf("ciphertext: %s\n", string);
}