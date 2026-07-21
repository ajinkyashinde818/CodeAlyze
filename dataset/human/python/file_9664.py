from sys import stdin,stdout
from collections import defaultdict
import sys
sys.setrecursionlimit(10**7)
def dfs1(src):
    global steps
    if steps==rem:return src
    steps+=1
    return dfs1(g[src][0])
def dfs(src):
    global steps,done,boc,nic
    vis[src]=1
    steps+=1
    if steps-1==k:
        print(src)
        exit(0)
    dfn[src]=steps
    for neigh in g[src]:
        if not vis[neigh]:dfs(neigh)
        else:
            boc,done,nic=[neigh,steps,steps-dfn[neigh]+1]
            # print(done,boc,nic)
            return

n,k=list(map(int,stdin.readline().split()))
done,boc,nic=0,0,0
a=list(map(int,stdin.readline().split()))
g=defaultdict(list)
for i in range(1,n+1):
    g[i]+=[a[i-1]]
vis=[0]*(n+1)
dfn=[0]*(1+n)
steps=0
dfs(1)
# print(done,boc,nic)
left=k-done
rem=(left%nic)
if rem==0:rem=nic
steps=1
print(dfs1(g[boc][0]))
