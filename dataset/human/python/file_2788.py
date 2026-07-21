from collections import defaultdict,deque
import sys,heapq,bisect,math,itertools,string,queue,datetime
sys.setrecursionlimit(10**8)
INF = float('inf')
mod = 10**9+7
def inpl(): return list(map(int, input().split()))
def inpls(): return list(input().split())

N,K = inpl()
L = K.bit_length()

koho = [K]
tmp = 0
for b in reversed(range(L)):
	if (K>>b) & 1:
		tmp += (1<<b)
		koho.append(tmp-1)

nums = [0]*len(koho)
for _ in range(N):
	A,B = inpl()
	for i,k in enumerate(koho):
		if k|A == k:
			nums[i] += B

print(max(nums))
