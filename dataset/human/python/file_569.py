import sys
import os
N = int(input())
A = list(map(int,input().split()))

negativeCnt = 0
for a in A:
    if a < 0:
        negativeCnt += 1
A = list(map(lambda a: -a if a < 0 else a, A))
miniA = min(A)
if negativeCnt%2 == 0:
    print(sum(A))
else:
    print(sum(A)-2*miniA)
