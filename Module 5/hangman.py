import random

lengths = []


class Lexicon:
    # Load the dictionary of all words, and make a list of all lengths
    def __init__(self):
        self.words = []
        file = open("dictionary.txt", "r")

        for line in file:
            word = line.rstrip("\n")
            self.words.append(word)

            if len(word) not in lengths:
                lengths.append(len(word))

        file.close()

    # Return a list of all words from the dictionary of the given length.
    def get_words(self, length):
        correct_words = []
        for word in self.words:
            if len(word) == length:
                correct_words.append(word)
        return correct_words

    # Return a single random word of given length. Uses `get_words` above.
    def get_word(self, length):
        return random.choice(self.get_words(length))


class Hangman:
    # Initialize game by choosing a word and creating an empty pattern.
    def __init__(self, length, num_guesses):
        lexicon = Lexicon()
        assert num_guesses > 0 and length in lengths
        self.length = length
        self.num_guesses = num_guesses
        self.word = list(lexicon.get_word(length))
        self.guessed_word = []
        self.guessed_letters = []

        [self.guessed_word.append("_") for _ in range(length)]

        print(self.pattern())

    # Update the game for a guess of letter. Return True if the letter
    # is added to the pattern, return False if it is not.
    def guess(self, letter):
        letter = str(letter)
        assert letter.isalpha() and len(letter) == 1 and letter not in self.guessed_letters
        self.guessed_letters.append(letter)
        changed = False
        for i in range(self.length):
            if self.word[i] == letter:
                self.guessed_word[i] = letter
                changed = True

        print(self.pattern())
        if changed == False:
            self.num_guesses -= 1
        return changed

    # Return a nice version of the pattern, for printing.
    def pattern(self):
        return "".join(self.guessed_word)

    # Returns True if the word has been guessed
    def won(self):
        if self.guessed_word == self.word:
            return True
        else:
            return False

    # Returns True if the amount of guesses has been reached, and the player hasn't won
    def lost(self):
        if self.num_guesses == 0:
            return True
        else:
            return False

    # Checks if either of the end conditions has been reached
    def finished(self):
        if self.won():
            return "won"
        elif self.lost():
            return "lost"
        return False

    def guessed_string(self):
        return "".join(self.guessed_letters)


def main():
    dictionary = Lexicon()

    # Asks the player for a valid length and amount of guesses
    while True:
        try:
            length = int(input("How long should the word be? "))
            if length not in lengths:
                raise Exception
            guesses = int(input("How many guesses do you want? "))
            if guesses < 0:
                raise Exception
        except:
            continue
        else:
            break

    game = Hangman(length, guesses)

    # Plays the game
    while True:
        # Repeat question until a valid guess is given
        while True:
            guess = input(f"Guess ({game.num_guesses} wrong guess(es) left): ")
            if guess.isalpha() and guess not in game.guessed_letters and len(guess) == 1:
                break

        game.guess(guess)

        # Check if the game is finished
        status = game.finished()
        if status == "won":
            print("Wow you did it congrats")
            break
        elif status == "lost":
            print(f"You're out of guesses, the word was {''.join(game.word)}")
            break

    while True:
        choice = input("Do you want to play again? (y/n) ")
        if choice == "y":
            main()
        elif choice == "n":
            break


if __name__ == "__main__":
    main()