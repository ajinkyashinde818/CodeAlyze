import sys
from collections import defaultdict
n, k = map(int, input().split())
a = [int(i) for i in input().split()]
towns = [1]
town_dic = defaultdict(lambda : 0)
prev = 1
count = 0
while True:
    next = a[prev - 1]
    count += 1
    if count == k:
        print(next)
        sys.exit()
    if town_dic[next] == 1:
        break
    else:
        town_dic[next] += 1
    towns.append(next)
    prev = next
i = towns.index(next)
repeat = towns[i:]
unit = len(repeat)
rest = k - count + 1
print(repeat[(rest % unit) - 1])
