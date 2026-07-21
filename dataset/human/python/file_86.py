import sys
import random
import itertools
sys.setrecursionlimit(20000000)
input = sys.stdin.readline
r,g,b,n = map(int,input().split())
ans = 0
for i in range(n+1):
    noko = n-r*i
    if noko < 0:
        break
    for j in range(n+1):
        noko = n-r*i
        noko = noko - g*j
        if noko < 0:
            break
        if noko % b == 0:
            ans += 1
print(ans)
