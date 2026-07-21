import numpy as np

N, K = list(map(int, input().split()))
A = np.fromstring(input(), int, sep=" ")

p = 1
count = 0
memo = {1: 0}
while count < K:
    p = A[p-1]
    count += 1

    if p not in memo:
        memo[p] = count
    else:
        step = count - memo[p]
        count += max(0, K-count) // step * step
        memo = {p: count}

print(p)
