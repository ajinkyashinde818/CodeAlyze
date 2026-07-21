import math

n = int(input())
a_list = [int(i) for i in input().split()]
sum = 0
ans = 0
mini = 10000000000
count = 0
for i in range(n):
    if a_list[i]<0:
        count += 1
    mini = min(mini,abs(a_list[i]))
    sum += abs(a_list[i])

if count%2==1:
    print(sum - 2*mini)
else:
    print(sum)
