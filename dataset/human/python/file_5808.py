import sys
input = sys.stdin.readline
sys.setrecursionlimit(1000000)
from collections import deque
def getN():
    return int(input())
def getList():
    return list(map(int, input().split()))
import math

n = getN()

anums = getList()
bnums = getList()
cnums = getList()

anums = [-100] + anums

ans = 0
for i, j in zip(anums, anums[1:]):
    ans += bnums[j-1]
    if j == i + 1:
        ans += cnums[i-1]


print(ans)
