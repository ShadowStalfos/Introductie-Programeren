#define _XOPEN_SOURCE
#include <unistd.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
int cracker(char* current_password, char* hashed_password, string salt);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Error: Not the right amount of arguments, please only use 1");
        return(1);
    }
    string cracked_password = "0";
    char* hashed_password = argv[1];
    char charactersalt[3] = {hashed_password[0], hashed_password[1], '\0'};
    string salt = charactersalt;
    char currentpassword[] = "\0\0\0\0\0";
    for (int x = 0; x <= 5; x+=1)
    {
        currentpassword[x] = 'A';
        if(cracker(currentpassword, hashed_password, salt) == 0)
        {
                return(0);
        }
    }
    return(1);
}

int cracker(char* current_password, char* hashed_password, string salt)
{
    int length = strlen(current_password);
    int i = 0;
    while(true)
    {
        char* current_hash = crypt(current_password, salt);
        if (strcmp(current_hash, hashed_password) == 0)
        {
            printf("%s \n", current_password);
            return (0);
        }
        current_password[0] = current_password[0] + 1;
        if (current_password[0] > 'z')
        {
            i = 0;
            while (current_password[i] > 'z')
            {
                if(i==length)
                {
                    return (1);
                }
                current_password[i] = 'A';
                current_password[i+1] = current_password[i+1] + 1;
                if (current_password[i+1] > 'Z' && current_password[i+1] < 'a')
                {
                    current_password[i+1] = 'a';
                }
                if(i+1 == length && current_password[i+1] > 'z')
                {
                    return (1);
                }
                i++;
            }
        }
    }
}