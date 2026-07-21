import math
length, goal = map(int, input().split(" "))
nums = []
sumall = []
for i in range(length):
    a, b = map(int, input().split(" "))
    nums.append(a)
    sumall.append(a * (i + 1) * 100 + b)
answer = float("inf")
for bit in range(2 ** length):
    temp = []
    for i in range(length - 1, -1, -1):
        if bit & (1 << i):
            temp.append(i)
    temp_length = len(temp)
    for tempbit in range(2 ** temp_length):
        temp_sum = 0
        choosed = 0
        for i in range(temp_length):
            if tempbit & (1 << i):
                temp_sum += sumall[temp[i]]
                choosed += nums[temp[i]]
                if temp_sum >= goal:
                    answer = min(answer, choosed)
                    break
            else:
                if temp_sum + (nums[temp[i]] - 1) * (temp[i] + 1) * 100 >= goal:
                    answer = min(answer, choosed + int(math.ceil((goal - temp_sum) / (100 * (temp[i] + 1)))) )
                    break
                temp_sum += (nums[temp[i]] - 1) * (temp[i] + 1) * 100
                choosed += nums[temp[i]] - 1
        # print(bin(bit), bin(tempbit), temp_sum, choosed, answer)
    # print(answer, bin(bit))
print(answer)
