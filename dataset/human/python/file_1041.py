import sys
def input():
    return sys.stdin.readline()[:-1]
from collections import *
from math import atan2, pi
from bisect import *
mod = 10**9+7

N = int(input())
S = [int(c == 'B') for c in input()]
if S[0] + S[-1] < 2:
    print(0)
    exit()
for i in range(N):
    S[2*i] ^= 1
if sum(S) != N:
    print(0)
    exit()
cnt, ans = 0, 1
for x in S:
    if x == 0:
        cnt += 1
    else:
        if cnt == 0:
            print(0)
            exit()
        ans = ans * cnt % mod
        cnt -= 1
for i in range(2, N+1):
    ans = ans * i % mod
print(ans)
