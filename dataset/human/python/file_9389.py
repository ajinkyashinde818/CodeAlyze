from collections import deque
import numpy as np
n, k = map(int, input().split())
An = list(map(int, input().split()))
root = deque([1])
check = np.zeros(n, np.int)
check[0] = 1
i = 0
dup = 1
cnt = 1
for _ in range(n):
    temp = An[i]
    if check[temp-1] == 1:
        dup = temp
        break
    root.append(temp)
    check[temp-1] = 1
    i = temp - 1
    cnt += 1
index = root.index(dup)
if index >= k:
    print(root[k])
elif index == cnt - 1:
    print(dup)
else:
    print(root[(k-index) % (cnt-index) + index])
