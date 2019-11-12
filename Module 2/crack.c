#define _XOPEN_SOURCE
#include <unistd.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

/*
* Brute force guesses a password with a given hash by going
* through all the possibilities between A - zzzzz, stopping
* when it finds a match
*
* Thomas Komen, 12556963
*/

int cracker(char *current_password, char *hashed_password, string salt);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Error: Not the right amount of arguments, please only use 1");
        return (1);
    }

    char *hashed_password = argv[1];
    char charactersalt[3] = {hashed_password[0], hashed_password[1], '\0'};
    string salt = charactersalt;
    char currentpassword[] = "\0\0\0\0\0"; // reserves 5 characters for currentpassword

    // Keeps adding an additional letter each time cracker fails
    for (int x = 0; x < 5; x += 1)
    {
        currentpassword[x] = 'A';
        if (cracker(currentpassword, hashed_password, salt) == 0)
        {
            return (0);
        }
    }
    return (1);
}

int cracker(char *current_password, char *hashed_password, string salt)
{
    int length = strlen(current_password);
    int i = 0;

    while (true)
    {
        // Hash the current password, and if the hash matches, print the password and succeed
        char *current_hash = crypt(current_password, salt);
        if (strcmp(current_hash, hashed_password) == 0)
        {
            printf("%s \n", current_password);
            return (0);
        }

        current_password[0] = current_password[0] + 1;

        if (current_password[0] > 'z')
        {
            i = 0;
            // If the first character exceeds a z, put it back to A and increase the next character
            // Run the same check for the next character, until a character doesn't exceed z anymore
            while (current_password[i] > 'z')
            {
                if (i == length)
                {
                    return (1);
                }
                current_password[i] = 'A';
                current_password[i + 1] = current_password[i + 1] + 1;
                if (current_password[i + 1] > 'Z' && current_password[i + 1] < 'a')
                {
                    current_password[i + 1] = 'a';
                }
                //If the program reaches the last character, and it exceeds z, fail
                if (i + 1 == length && current_password[i + 1] > 'z')
                {
                    return (1);
                }
                i++;
            }
        }
    }
}