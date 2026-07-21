from collections import defaultdict,deque
import sys,heapq,bisect,math,itertools,string,queue,datetime
sys.setrecursionlimit(10**8)
INF = float('inf')
mod = 10**9+7
eps = 10**-7
def inpl(): return list(map(int, input().split()))
def inpl_s(): return list(input().split())

ss = list(input())
tt = list(input())
ss.sort()
tt.sort(reverse=True)
S = ''
T = ''
for s in ss:
	S = S + s
for t in tt:
	T = T + t

if S < T:
	print('Yes')
else:
	print('No')
