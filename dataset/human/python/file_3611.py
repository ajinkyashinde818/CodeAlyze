from sys import stdin
from math import sqrt
input = stdin.readline
N = int(input())

s = [0] * (int(sqrt(N)) + 1)

ans = 0

for i in range(2, int(sqrt(N)) + 1):
    tmp = i

    while N % tmp == 0:
        N //= tmp
        s[tmp] += 1

for i in s:
    for j in range(10 ** 5):
        if (j * (j + 1)) // 2 > i:
            k = j
            break

    ans += k - 1

for i in range(2, int(sqrt(N)) + 1):
    if N % i == 0:
        print(ans)
        exit()

if N != 1:
    ans += 1


print(ans)
