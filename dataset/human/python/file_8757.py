import numpy as np

dummy = list(map(int, input().split(" ")))
K = dummy[0]
N = dummy[1]
A = np.array(list(map(int, input().split(" "))))
Distance = A - np.roll(A, 1)
Distance[0] = K - sum(Distance[1:])
#out = sum(A) - max(A)
#print(A, Distance)
out = K - max(Distance)
print(out)
