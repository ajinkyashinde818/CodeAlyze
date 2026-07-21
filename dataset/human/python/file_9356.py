import numpy as np
import itertools
n, k = map(int, input().split())
a = list(map(int, input().split()))

now = 1
town_list = [0]*n
town_list[0] = 1
tn_list = [1]

while(1):
    next = a[now-1]
    now = next
    if town_list[now-1] == 0:
        town_list[now-1] = 1
        tn_list.append(now)

    else:
        idx = tn_list.index(now)
        initial = tn_list[:idx]
        cycle = tn_list[idx:]
        break

if k >= len(initial):
    end_idx = (k-len(initial))%len(cycle)
    print(cycle[end_idx])
else:
    print(initial[k])
