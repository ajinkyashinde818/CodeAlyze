import numpy as np
N = int(input())
A = np.array(list(map(int, input().split())))
B = np.array(list(map(int, input().split())))
C = np.array(list(map(int, input().split())))

tmp = A[1:]

tmp = np.append(tmp, -1)

add = A[np.where((tmp-A)==1)]

ans = B.sum() + C[add-1].sum()
print(ans)
