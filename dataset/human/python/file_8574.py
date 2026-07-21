import numpy as np
 
k, n = map(int, input().split())
arr = list(map(int, input().split()))
diff = [0] * n
 
for i in range(1, n):
  diff[i] = arr[i] - arr[i-1]
diff[0] = k - arr[-1] + arr[0]
 
print(int(np.sum(diff) - max(diff)))
