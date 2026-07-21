import sys
sys.setrecursionlimit(10**6)

N,M = map(int,input().split())
G = [[] for i in range(N)]
for i in range(M):
	a,b = map(lambda x: int(x)-1, input().split())
	G[a].append(b)
	G[b].append(a)

flag = False

def dfs(p, x, d):
	if d>=2:
		if x==N-1:
			global flag
			flag = True
		return

	for i in G[x]:
		if i==p:
			continue
		else:
			dfs(x,i,d+1)

dfs(-1,0,0)
print('POSSIBLE' if flag else 'IMPOSSIBLE')
