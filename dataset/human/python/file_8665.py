import numpy as np
K, N = map(int, input().split())
A = list(map(int, input().split()))
ans = 0
A = sorted(A)
new = []
for i in range(N-1):
    new.append(A[i+1]-A[i])
new.append(K + A[0] - A[-1])
new = sorted(new)
print(sum(new[:-1]))
