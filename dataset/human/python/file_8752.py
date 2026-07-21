k, n = map(int, input().split())
a = list(map(int, input().split()))
import numpy as np

x = np.array(a)
a1 = x[1:] - x[:-1]

ans = list(a1)
ans.append((k-a[-1])+a[0])

print(int(k-max(ans)))
