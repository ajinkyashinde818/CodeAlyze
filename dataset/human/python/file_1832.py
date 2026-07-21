import numpy as np
n,m = map(int,input().split())
a = np.array([list(input()) for _ in range(n)])
b = np.array([list(input()) for _ in range(m)])
flg = 0
for i in range(n-m+1):
  for j in range(n-m+1):
    if (a[i:i+m,j:j+m] == b).all():
      flg = 1
print("Yes" if flg == 1 else "No")
