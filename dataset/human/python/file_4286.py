import sys
import math

sys.setrecursionlimit(10**7)

n = int(input())
l = []
if n%2 == 0:
    l.append(0)
    while n%2 == 0:
        l[0] += 1
        n /= 2

i = 3
while i*i <= n:
    if n%i == 0:
        l.append(0)
        while n%i == 0:
            l[-1] += 1
            n /= i
    i += 2
if n != 1:
    l.append(1)

ans = 0
for i in range(len(l)):
    j = 1
    while True:
        l[i] -= j
        j += 1
        if l[i] < 0:
            break
        ans += 1
print(ans)
