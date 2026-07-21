from collections import Counter, defaultdict, deque

K, N = [int(x) for x in input().split()]
A = [int(x) for x in input().split()]

minDist = K + A[0] - A[-1]
for x, y in zip(A, A[1:]):
    minDist = max(minDist, y - x)
print(K - minDist)
