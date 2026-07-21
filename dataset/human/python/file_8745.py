import numpy as np

K, N = map(int, input().split())
A = list(map(int, input().split()))
B = np.roll(A, -1)
delta = B - A
delta = list(delta % K)
saidai = max(delta)

delta.remove(saidai)

print(sum(delta))
