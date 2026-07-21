import sys
input=sys.stdin.readline
sys.setrecursionlimit(10**6)
n,m=map(int,input().split())

edges=[[] for i in range(n)]
for i in range(m):
    a,b=map(int,input().split())
    a-=1
    b-=1
    edges[a].append(b)
    edges[b].append(a)
def dfs(cnt,v,before=-1):
    if cnt>=2:
        return False
    ans=False
    for to in edges[v]:
        if to!=before:
            if to==n-1:
                return True
            else:
                ans|=dfs(cnt+1,to,v)
    return ans

if dfs(0,0):
    print('POSSIBLE')
else:
    print('IMPOSSIBLE')
