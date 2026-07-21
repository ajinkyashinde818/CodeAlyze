from collections import defaultdict
n, k = map(int, input().split())
a = [0] + [int(i) for i in input().split()]
d = defaultdict(int)
next = 1
for t in range(k):
  if d[next]!=0:
    period = t - d[next]
    res = (k - t)%period
    for _ in range(res):
      next = a[next]
    break
  elif d[next]==0:
    d[next] = t
    next = a[next]
print(next)
