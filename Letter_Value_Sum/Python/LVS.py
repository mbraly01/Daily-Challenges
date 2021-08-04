string = "!"
while not string.isalpha():
    string = input("Enter a string (no special characters. only letters): ")

string = string.lower()
total = 0
for char in string:
    total += ord(char)
total -= 96 * len(string)
print(total)
