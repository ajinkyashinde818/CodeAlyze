N = int(input())
A = list(map(int, input().split()))

from functools import reduce

SUM = reduce(lambda x,y: abs(x) + abs(y) , A)

cntMinu = 0
for a in A:
    if a < 0 : cntMinu += 1

if cntMinu % 2 == 0:
    print(SUM)
    exit()

minAbs = 10**9 + 1
for a in A:
    if minAbs > abs(a): minAbs = abs(a)

print(SUM - 2 * minAbs )
