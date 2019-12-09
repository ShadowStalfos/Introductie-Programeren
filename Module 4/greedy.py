# Asks the user for an amount of dollars, which it converts to pennies. It then
# checks for the biggest coin that fits in this amount. By doing this it eventually
# finds the minimum amount of coins needed for the given amount

# Thomas Komen, 12556963

# checks if the given amount is a positive number
while(True):
    try:
        change = float(input("O hai! How much change is owed? "))
        if change < 0:
            raise Exception
    except:
        continue

    else:
        break

# converts dollars to pennies
coins = 0
change = int(change*100)

# goes through all coins and checks how many times it fits
while change >= 25:
    change -= 25
    coins += 1

while change >= 10:
    change -= 10
    coins += 1

while change >= 5:
    change -= 5
    coins += 1

while change >= 1:
    change -= 1
    coins += 1

print(coins)