nums = []

print("Please enter as many digits as you would like.")
print("type any letter to stop")
# while True:
#     inp = input()
#     if inp.isalpha():
#         break
#     else:
#         nums.append(int(inp))

nums = [1,0,-1,0,-2,2]
target = 0


nums_dict = {}
for i in nums:
    if i in nums_dict:
        nums_dict[i] += 1
    else:
        nums_dict[i] = 1

final = []
for i in nums_dict:
    if nums_dict[i] != 0:
        temp = [nums_dict[i]]
        nums_dict[i] -= 1
        nums_2 = nums_dict.copy()
        if nums_dict[i] == 0:
            del nums_2[i]
        for j in nums_2:
            temp2 = temp.copy()
            temp2.append(j)
            nums_2[j] -= 1
            nums_3 = nums_2.copy()
            if nums_2[j] == 0:
                del nums_3[j]
            count = 0
            for k in nums_3:
                temp3 = temp2.copy()
                temp3.append(k)
                nums_3[k] -= 1
                if -(temp3[0] + temp3[1] + temp3[2]) in nums_3:
                    if nums_3[-(temp3[0] + temp3[1] + temp3[2])] > 0:
                        isValid = False
                        temp3.append(-(temp3[0] + temp3[1] + temp3[2]))
                        temp3.sort()
                        if temp3 not in final:
                            final.append(temp3)
                        temp3 = temp2
                        break
                


print(final)
