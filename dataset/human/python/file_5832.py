import sys
def input():
    return sys.stdin.readline()[:-1]
sys.setrecursionlimit(1000000)
from collections import *
from bisect import *
mod = 10**9+7

n = int(input())
a = [int(x) for x in input().split()]
b = [int(x) for x in input().split()]
c = [int(x) for x in input().split()]
ans = sum(b)
for i, j in zip(a, a[1:]):
    if i+1 == j:
        ans += c[i-1]
print(ans)
