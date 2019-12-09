# Takes two words as input, and ciphers each letter in the second word with a
# specific letter from the given keyword

# Thomas Komen, 12556963

import sys

# converts a given letter to its value between a = 0 and z = 25
def getvalue(character):
    if(character.isupper()):
        return ord(character) - ord('A')
    else:
        return ord(character) - ord('a')


if len(sys.argv) != 2:
    print("usage: python vigenere.py keyword")
    exit()

keyword = sys.argv[1]

plaintext = input("Plaintext: ")

x = 0
ciphertext = []

for letter in plaintext:
    if(letter.isalpha()):
        key = getvalue(keyword[x])
        plainvalue = getvalue(letter)

        # Combines the letter and key to a value between 0-25, and makes it into a letter
        ciphervalue = (plainvalue + key) % 26
        if letter.isupper():
            ciphertext.append(chr(ciphervalue+ord('A')))
        else:
            ciphertext.append(chr(ciphervalue+ord('a')))

        x = (x + 1) % len(keyword)

    else:
        ciphertext.append(letter)

print('ciphertext: ' + ''.join(ciphertext))