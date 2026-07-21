import sys,math,copy,queue,itertools
from fractions import gcd
sys.setrecursionlimit(10**7)
LI = lambda : [int(x) for x in sys.stdin.readline().split()]
_LI = lambda : [int(x)-1 for x in sys.stdin.readline().split()]
NI = lambda : int(sys.stdin.readline())
INF = 10**18
MOD = 10**9 + 7
DD = ((1,0),(0,1),(-1,0),(0,-1))
K,N = LI()
A = LI()
A = A + [A[0]+K]
ans = 0
for i in range(N):
    ans = max(ans,A[i+1]-A[i])
print (K - ans)
