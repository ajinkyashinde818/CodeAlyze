import sys

sys.setrecursionlimit(10000000)
N,K = [int(v) for v in input().split()]
A = [int(v) for v in input().split()]

loop = []
pre = []
visited = set()

def dfs(index,now):
    global pre
    global loop
    loop.append(now)
    if now in visited:
        for left in range(len(loop)):
            if now == loop[left]:
                break
        pre = loop[:left]
        loop = loop[left:index]
        return
    else:
        visited.add(now)
        dfs(index+1,A[now-1])
dfs(0,1)

if len(pre) > K:
    print(pre[K])
else:
    K-=len(pre)
    print(loop[K%len(loop)])
