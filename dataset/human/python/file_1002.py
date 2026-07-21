import sys, math
from collections import deque

readline = sys.stdin.readline

N = int(readline())
S = readline().strip()

P = 10 ** 9 + 7

d = 0
count = 1
for c in S:
    if d % 2 == 0:
        if c == 'B':
            d += 1
        else:
            count *= d
            count %= P
            d -= 1
    else:
        if c == 'B':
            count *= d
            count %= P
            d -= 1

        else:
            d += 1
    if d < 0:
        print(0)
        exit(0)

if d != 0:
    print(0)
    exit(0)

ans = count
for i in range(1, N + 1):
    ans *= i
    ans %= P

print(ans)
