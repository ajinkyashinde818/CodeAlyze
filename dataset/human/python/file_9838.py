import sys
n, k = map(int,input().split())
a = list(map(int,input().split()))
t = [0]*(n + 1) # 1-indexed
vis = []

mod_max = n
rep_start = n
cur = 1
flag = 0
for i in range(0,k + 1):
    if t[cur] > 0:
        mod_max = i
        rep_start = vis.index(cur)
        flag = 1
        break
    t[cur] += 1
    vis.append(cur)
    cur = a[cur - 1]
if flag == 0:
    print(vis[-1])
    sys.exit()
mod = mod_max - rep_start
vis_mod = vis[mod_max - mod:]
# print(mod_max,mod)
# print(rep_start)
# print(vis, vis_mod)
# print(mod, len(vis_mod))
print(vis_mod[(k - (mod_max - mod))%mod])
