import sys
readline = sys.stdin.buffer.readline
def even(n): return 1 if n%2==0 else 0
"""
閉路をmodを取って出力
閉路になっていない(回帰するなら)ならそこを出力
"""
n,k = map(int,readline().split())
lst1 = list(map(int,readline().split()))


visited = [-1]*n #modを取った時にそこにたどり着く
visited[0] = 0
now = 0
count = 1
mod = -1
lim = -1
while True:
    now = lst1[now] -1
    if visited[now] != -1: #閉路
        mod = count - visited[now]
        lim = visited[now]
        break
    visited[now] = count

    count += 1
    
if k <= lim:
    for i in range(n):
        if visited[i] == k:
            print(i+1)
            exit()
else:
    res = (k-lim)%mod
    for i in range(n):
        if visited[i]-lim == res:
            print(i+1)
            exit()
