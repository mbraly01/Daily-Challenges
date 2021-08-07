amount = int(input("What is the amount you want to get change for?"))

total_change = 0
change_types = [500,100,25,10,5,1]

for i in change_types:
    total_change += amount // i
    amount %= i
print(total_change)