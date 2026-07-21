import sys
input = sys.stdin.readline
from collections import *

R, G, B, N = map(int, input().split())
ans = 0

for i in range(N+1):
    for j in range(N+1):
        if N-R*i-G*j>=0 and (N-R*i-G*j)%B==0:
            ans += 1

print(ans)
