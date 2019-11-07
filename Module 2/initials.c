#include <cs50.h>
#include <stdio.h>
#include <string.h>

char lower_to_upper(char letter);

int main(void)
{
    char* name = get_string("Give Name: ");
    int length = strlen(name);
    int j = 0;
    while(name[j] == 32)
    {
        j++;
    }
    printf("%c", lower_to_upper(name[j]));
    for (int i = j; i < length-1; i++)
    {
        if(name[i] == 32 && !(name[i+1] == 32))
        {
            printf("%c", lower_to_upper(name[i+1]));
        }
    }
    printf("\n");
}

char lower_to_upper(char letter)
{
    if(letter >= 97)
    {
        return(letter-32);
    }
    else
    {
        return(letter);
    }
}
