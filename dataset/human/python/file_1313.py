import numpy as np

n = int(input())
a = [int(i) for i in input().split()]

cum_sum = np.cumsum(a)
track_min = float('inf')

for i in range(n-1):
    x = int(cum_sum[i])
    y = int(cum_sum[-1]-cum_sum[i])
    diff = abs(x-y)
    if diff<track_min:
        track_min = diff
    
print(track_min)
