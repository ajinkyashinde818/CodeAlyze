import sys

N = int(input())
A = list(map(int, sys.stdin.readline().rsplit()))

cnt = 0
S = 0
minA = 10 ** 9
for a in A:
    if a < 0:
        cnt += 1
    minA = min(minA, abs(a))
    S += abs(a)

if cnt % 2 == 0:
    res = S
else:
    res = S - 2 * minA

print(res)
