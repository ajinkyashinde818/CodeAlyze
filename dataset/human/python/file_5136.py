from collections import defaultdict
import sys,heapq,bisect,math,itertools,string,queue,datetime
sys.setrecursionlimit(10**8)
INF = float('inf')
mod = 10**9+7
eps = 10**-7
AtoZ = [chr(i) for i in range(65,65+26)]
atoz = [chr(i) for i in range(97,97+26)]

def inpl(): return list(map(int, input().split()))
def inpl_str(): return list(input().split())

N,M = inpl()
dd = defaultdict(int)

for i in range(M):
	a,b = inpl()
	if a == 1:
		if dd[b] == 1:
			print('POSSIBLE')
			sys.exit()
		else:
			dd[b] = 1

	if b == N:
		if dd[a] == 1:
			print('POSSIBLE')
			sys.exit()
		else:
			dd[a] = 1

print('IMPOSSIBLE')
