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
    char* key = argv[1];
    int length = strlen(string);
    int keylength = strlen(key);
    int x = -1;
    int shift = 0;
    for (int i = 0; i < length; i++)
    {
        if(isalpha(string[i]))
        {
            x++;
            if(x == keylength)
            {
                x = 0;
            }

            if(key[x] >= 'A' && key[x] <= 'Z')
            {
                shift = key[x] - 65;
            }
            else
            {
                shift = key[x] - 97;
            }
            //printf("%i\n", shift);
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