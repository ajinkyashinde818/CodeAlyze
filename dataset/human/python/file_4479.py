from sys import *
from collections import Counter
N = int(stdin.readline())
things = []
if N ==1:
    print(0)
    exit()
for i in range(2,N):
    if i*i > N:
        if len(things) == 0:
            print(1)
            exit()
        if N > 1:
            things.append(int(N))
        break
    while(N%i == 0):
        things.append(i)
        N = N/i
c = Counter(things)
vals = 0
for item in c:
    hue = 0
    for i in range(1,100000):
        if (hue + i) > c[item]:
            break
        else:
            hue += i
            vals += 1

print(vals)
