import numpy as np
n = int(input())
a = np.array([int(i) for i in input().split(" ")])
b = [int(i) for i in input().split(" ")]
c = np.array([int(i) for i in input().split(" ")])

ans = sum(b)
diff = np.diff(a)
mask = diff == 1
mask2 = a[mask]-1
ans += np.sum(c[mask2])
print(ans)
