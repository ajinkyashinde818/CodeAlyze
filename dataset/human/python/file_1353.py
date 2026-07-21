from collections import defaultdict
import sys,heapq,bisect,math,itertools,string,queue
sys.setrecursionlimit(10**8)
INF = float('inf')
mod = 10**9+7
eps = 10**-7
AtoZ = [chr(i) for i in range(65,65+26)]
atoz = [chr(i) for i in range(97,97+26)]

def inpl(): return list(map(int, input().split()))
def inpl_str(): return list(map(int, input().split()))

N = int(input())
aa = inpl()

S1 = 0
S2 = sum(aa)
ans = INF

for i,a in enumerate(aa):
	if i == N-1:
		break
	S1 += a
	S2 -= a
	ans = min(abs(S1-S2),ans)

print(ans)
