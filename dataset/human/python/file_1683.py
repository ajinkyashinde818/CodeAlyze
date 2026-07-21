import numpy as np
n, m = map(int, input().split())
A = np.array([input() for i in range(n)])
B = [input() for i in range(m)]

flag = "No"
diff = n - m + 1
for i in range(diff):
  for j in range(diff):
    T = []
    for k in range(m):
      T.append(A[i+k][j:j+m])
    if T == B:
      flag = "Yes"
      break

print(flag)
