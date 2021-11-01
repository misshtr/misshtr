x = 55
i = 0
while (x >= i):
    i = (i + 1)
    if (i % 5 == 0) and (i % 3 == 0):
        print('Gumigam')
    elif (i % 3 == 0):
        print('Shoko')
    elif (i % 5 == 0):
        print('Bo')

    else:
        print(i)