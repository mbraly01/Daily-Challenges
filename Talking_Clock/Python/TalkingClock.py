import csv
from time import gmtime, strftime
import time
from gtts import gTTS
from playsound import playsound

#Creates a dictionary containing all the time zones
tz_dict = {}
with open('TimeZones.csv', 'r') as csv_file:
    tz_reader = csv.reader(csv_file, delimiter=',')
    for row in tz_reader:
        time_split = row[2].split(" ")
        tz_dict[row[0]] = time_split[0]
gmt_time = time.strftime("%I:%M:%S %p", time.gmtime())

#gets timezone input
print("Welcome to the talking clock")
timezone = input("What timezone are you in?")
while (not timezone.isalpha()) or (timezone.upper() not in tz_dict.keys()):
    timezone = input("What timezone are you in? (e.g. EST)")

#Finds timezone and gets correct time
timezone = timezone.upper()
tz_colon = tz_dict[timezone].split(":")
gmt_split = gmt_time.split(":")
tz_hour = int(tz_colon[0]) + int(gmt_split[0])
tz_min = int(gmt_split[1])
ampm = gmt_time.split(" ")[1]

#Corrects time based on selected timezone
if len(tz_colon) > 1:
    tz_min += int(tz_colon[0][0] + tz_colon[1])
    if tz_min < 0:
        tz_hour -= 1
        tz_min += 60
    if tz_min > 59:
        tz_hour += 1
        tz_min = 60 - tz_min
if (tz_hour < 0):
    tz_hour = 24 + tz_hour
    if (tz_hour > 11):
        tz_hour -= 12
        ampm = "PM"
    else:
        ampm = "AM"
tz_str = str(tz_hour) + ":" + str(tz_min) + ":" + ampm

#converts integer values to strings
tz_final_split = tz_str.split(":")
tz_final_str = ""
if tz_final_split[0] == "1":
    tz_final_str = "It's One "
elif tz_final_split[0] == "2":
    tz_final_str = "It's Two "
elif tz_final_split[0] == "3":
    tz_final_str = "It's Three "
elif tz_final_split[0] == "4":
    tz_final_str ="It's Four "
elif tz_final_split[0] == "5":
    tz_final_str = "It's Five "
elif tz_final_split[0] == "6":
    tz_final_str = "It's Six "
elif tz_final_split[0] == "7":
    tz_final_str = "It's Seven "
elif tz_final_split[0] == "8":
    tz_final_str = "It's Eight "
elif tz_final_split[0] == "9":
    tz_final_str = "It's Nine "
elif tz_final_split[0] == "10":
    tz_final_str = "It's Ten "
elif tz_final_split[0] == "11":
    tz_final_str = "It's Eleven "
elif tz_final_split[0] == "12":
    tz_final_str = "It's Twelve "

tz_final_min = int(tz_final_split[1])
if tz_final_min < 10:
    tz_final_str += "o' "
elif tz_final_min > 19 and tz_final_min < 30:
    tz_final_str += "twenty "
elif tz_final_min > 29 and tz_final_min < 40:
    tz_final_str += "thirty "
elif tz_final_min > 39 and tz_final_min < 50:
    tz_final_str += "forty "
elif tz_final_min > 49 and tz_final_min < 60:
    tz_final_str += "fifty "

if tz_final_min == 10:
    tz_final_str += "ten"
elif tz_final_min == 11:
    tz_final_str += "eleven"
elif tz_final_min == 12:
    tz_final_str += "twelve"
elif tz_final_min == 13:
    tz_final_str += "thirteen"
elif tz_final_min == 14:
    tz_final_str += "fourteen"
elif tz_final_min == 15:
    tz_final_str += "fifteen"
elif tz_final_min % 10 == 1:
    tz_final_str += "one"
elif tz_final_min % 10 == 2:
    tz_final_str += "two"
elif tz_final_min % 10 == 3:
    tz_final_str += "three"
elif tz_final_min % 10 == 4:
    tz_final_str += "four"
elif tz_final_min % 10 == 5:
    tz_final_str += "five"
elif tz_final_min % 10 == 6:
    tz_final_str += "six"
elif tz_final_min % 10 == 7:
    tz_final_str += "seven"
elif tz_final_min % 10 == 8:
    tz_final_str += "eight"
elif tz_final_min % 10 == 9:
    tz_final_str += "nine"

if tz_final_min > 15 and tz_final_min < 20:
    tz_final_str += "teen"

tz_final_str += " " + tz_final_split[2]
print(tz_final_str)

#Getting the computer to talk
language = 'en'

myobj = gTTS(text=tz_final_str, lang=language, slow=False)
myobj.save("time.mp3")

playsound('time.mp3')
