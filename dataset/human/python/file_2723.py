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

D,G = inpl()

flags = []
for i in range(2**D):
	t = format(i,'010b')
	flags.append(list(t[10-D:10]))

pp = [0]
cc = [0]
Comp = [0]
for i in range(1,D+1):
	p,c = inpl()
	pp.append(p)
	cc.append(c)
	Comp.append(p*i*100+c)

ans = INF
for flag in flags:
	SUM  = num = 0
	for i,fl in enumerate(flag):
		if fl == '1':
			SUM += Comp[i+1]
			num += pp[i+1]

	if SUM >= G:
		ans = min(ans,num)
	else:
		nn = -1
		delta = G - SUM
		for i in reversed(range(D)):
			if flag[i] == '1':
				continue
			else:
				nn = i+1
				break
		if nn != -1:
			if nn*100*pp[nn] >= delta:
				num += (delta-1)//(nn*100) + 1
				ans = min(ans,num)

print(ans)
