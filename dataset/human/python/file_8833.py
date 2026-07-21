k, n = map(int, input().split())
import numpy as np
a = np.array(list(map(int, input().split())))
dist = np.abs(a -np.roll(a, 1))
dist[0] = min(k-a[n-1] + a[0], a[n-1]-a[0])
ans_a = np.sum(dist)
ans = ans_a
for i in range(n):
  ans_sub = ans_a-dist[i]
  if ans_sub < ans:
    ans = ans_sub
print(ans)
