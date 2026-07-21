import sys
input = sys.stdin.readline
from collections import *

N = int(input())
S = list(input()[:-1])

for i in range(2*N):
    if (2*N-i-1)%2==1:
        if S[i]=='B':
            S[i] = 'W'
        else:
            S[i] = 'B'
    
if S.count('B')!=N:
    print(0)
    exit()

w = 0
ans = 1
MOD = 10**9+7

for i in range(2*N):
    if S[i]=='W':
        w += 1
    else:
        ans *= w
        w -= 1
        ans %= MOD

for i in range(1, N+1):
    ans *= i
    ans %= MOD

print(ans)
