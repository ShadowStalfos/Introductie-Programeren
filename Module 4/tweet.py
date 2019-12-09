import helpers


def makelist(tweets, positives, negatives):
    # Makes a list, where each value in that list represents the sentiment of
    # the tweet with the same index

    sentiment_list = []
    positive_words = set(positives)
    negative_words = set(negatives)

    # Calculates the difference between the amount of positive and negative
    # words for every tweet, and represents that difference with a 1 for positive,
    # -1 for negative and 0 for neutral
    for i in range(len(tweets)):
        tweet = set(tweets[i])
        positive_value = len(positive_words & tweet)
        negative_value = len(negative_words & tweet)
        if(positive_value > negative_value):
            sentiment_list.append(1)
        elif(negative_value > positive_value):
            sentiment_list.append(-1)
        else:
            sentiment_list.append(0)

    return sentiment_list


def classify(tweets, positives, negatives):
    """
    classify all tweets in filename
    prints the number of tweets classified as either
    positive / negative / neutral
    """
    sentiment_list = makelist(tweets, positives, negatives)
    n_positives = 0
    n_negatives = 0
    n_neutral = 0

    # Counts the amount of times each number is in sentiment_list
    for i in sentiment_list:
        if i == 1:
            n_positives += 1
        elif i == -1:
            n_negatives += 1
        else:
            n_neutral += 1

    print("Trump's tweets classified:")
    print("    positive: {}".format(n_positives))
    print("    negative: {}".format(n_negatives))
    print("    neutral : {}".format(n_neutral))


def positive_word(tweets, positives):
    """prints the top 5 most used positive words"""

    wordcount = {}

    positive_words = set(positives)

    # Makes a dictionary of all positive words to be able to store the appearances
    for i in positives:
        wordcount[i] = 0

    for tweet in tweets:
        for word in tweet:
            if word in positive_words:
                wordcount[word] += 1

    # Sorts the dictionary so the first 5 words are the top used words
    items = wordcount.items()
    sorted_dic = sorted(items, key=lambda wordcount: wordcount[1], reverse=True)
    print("\nTrump's top 5 most used positive words:")
    for i in range(5):
        print("    " + sorted_dic[i][0] + " " + str(sorted_dic[i][1]))


def bad_days(dates, tweets, positives, negatives):
    """
    prints all days that trump
    tweeted more negatively than positively
    """

    sentiment_list = makelist(tweets, positives, negatives)
    print("\nTrump's bad days:")
    i = 0

    # Adds all the sentiment scores of a certain day, and determines if
    # its total is negative, printing if it is
    while i < len(dates):
        date = dates[i]
        sentiment_score = 0
        while(i < len(dates) and dates[i] == date):
            sentiment_score += sentiment_list[i]
            i += 1
        if(sentiment_score < 0):
            print("     "+date)


if __name__ == "__main__":
    # get the dates and tweets from tweet_filename
    dates, tweets = helpers.read_tweets("trump.txt")

    # get the lists of negative and positive words
    positives = helpers.read_words("positive_words.txt")
    negatives = helpers.read_words("negative_words.txt")

    classify(tweets, positives, negatives)
    positive_word(tweets, positives)
    bad_days(dates, tweets, positives, negatives)