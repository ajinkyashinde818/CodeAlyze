import numpy as np
from collections import Counter
R,G,B,N = list(map(int, input().split()))
a = [R, G, B]
a.sort()
a = a[::-1]
R, G, B = a

s = 0
r_cand = np.arange(0, N + 1, R)[:, None]
g_cand = np.arange(0, N + 1, G)[None, :]
rest = N - r_cand - g_cand
rest = rest[rest >= 0]
c = Counter(rest)

s = 0
for k in c.keys():
    s += (k%B == 0) * c[k]

print(s)
