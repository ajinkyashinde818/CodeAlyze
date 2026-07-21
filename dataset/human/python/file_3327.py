from collections import defaultdict as dd
from sys import exit
n = int(input())
if n == 1:
    print(0)
    exit()

counter = dd(int)
for num in range(2, int(n**0.5) + 3):
    while n % num == 0:
        n //= num
        counter[num] += 1
if n != 1:
    counter[n] += 1

total = 0
for key, val in counter.items():
    for i in range(1, 10**10):
        if i * (i + 1) // 2 > val:
            total += i-1
            break
print(total)
