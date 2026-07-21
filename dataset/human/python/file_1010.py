from collections import defaultdict,deque
import sys,heapq,bisect,math,itertools,string,queue,copy,time
sys.setrecursionlimit(10**8)
INF = float('inf')
mod = 10**9+7
eps = 10**-7
def inp(): return int(sys.stdin.readline())
def inpl(): return list(map(int, sys.stdin.readline().split()))
def inpl_str(): return list(sys.stdin.readline().split())

N = inp()
S = list(input())

dp = [0]*(2*N)

cnt = 0
ans = 1
for i in range(2*N):
    s = S[i]
    if s == 'B':
        if cnt%2 == 0:
            cnt += 1
            ans *= cnt
        else:
            cnt -= 1
    elif s == 'W':
        if cnt%2 == 0:
            cnt -= 1
        else:
            cnt += 1
            ans *= cnt
    ans %= mod


for i in range(1,N+1):
    ans *= i
    ans %= mod

if cnt != 0 or S[0]=='W' or S[-1]=='W':
    print(0)
else:
    print(ans%mod)
