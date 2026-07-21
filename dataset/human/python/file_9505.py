import sys
n, k = map(int,input().split())
a = [int(x) for x in input().split()]

vis_ti = [-1] * n
vis_at = [0]
now = 0

for i in range(1, k+1):
  now = a[now] - 1
  if vis_ti[now] >= 0:
    bgn = vis_ti[now]
    print(vis_at[bgn + (k - bgn) % (i - bgn)] + 1)
    sys.exit()
  vis_ti[now] = i
  vis_at.append(now)

print(vis_at[-1]+1)
