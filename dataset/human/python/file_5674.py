from collections import defaultdict
import sys,heapq,bisect,math,itertools,string,queue,datetime
sys.setrecursionlimit(10**8)
INF = float('inf')
mod = 10**9+7
eps = 10**-7
def inpl(): return list(map(int, input().split()))
def inpl_s(): return list(input().split())

S = input()
Sx = S.replace('x','')

if Sx == Sx[::-1]:
	xx = []
	tmp = 0
	for s in S:
		if s == 'x':
			tmp += 1
		else:
			xx.append(tmp)
			tmp = 0
	xx.append(tmp)
	ans = 0
	L = len(xx)
	for i in range(L//2):
		ans += abs(xx[i]-xx[L-1-i])
	print(ans)
else:
	print(-1)
