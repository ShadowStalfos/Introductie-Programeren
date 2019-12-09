# checks if the given input is a number between 0 and 23
while(True):
    try:
        height = int(input("Height: "))
        if height < 0 or height > 23:
            raise Exception
    except:
        continue
    else:
        break

# prints layer+1 #s, and spaces so that the total is always height+1 long
for layer in range(1, height+1):
    print(" "*(height-layer), end='')
    print("#"*(layer+1))