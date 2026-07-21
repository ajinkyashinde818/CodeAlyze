import numpy as np

K, N = map(int, input().split())
A = [int(x) for x in input().split()]
A.append(K+A[0])

diff_A = []
for i in range(N):
    diff_A.append(A[i+1] - A[i])
diff_max = max(diff_A)
print(K - diff_max)
