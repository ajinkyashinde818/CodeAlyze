import sys
import math
sys.setrecursionlimit(10**9)
MOD = 10**9+7

N = int(input())
*B, = map(int,input().split())
A = []
for i in range(N-1):
    A.append(B[i+1]-B[i])

S = []
f = math.factorial(N-1)
cur = 0
for i in range(1,N):
    cur += pow(i,MOD-2,MOD)
    S.append(cur)

sm  = 0
for a,b in zip(A,S):
    sm += (a*b)%MOD

print((sm*f)%MOD)
