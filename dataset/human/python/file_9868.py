from collections import deque
import numpy as np

N, K = map(int, input().split())

tele = list(input().split())
tele = np.array([int(tele[i]) for i in range(N)])
seen = set([])
roop_in = deque([])
now = 1
w_num = 0

while now not in seen and w_num < K:
    seen.add(now)
    roop_in.append(now)
    now = tele[now - 1]
    w_num += 1

if w_num == K:
    print(now)
else:
    roop_in_index = roop_in.index(now)
    roop = list(roop_in)[roop_in_index:]
    roop_len = len(roop)
    last = (K - (w_num - 1)) % roop_len
    print(roop[last - 1])
