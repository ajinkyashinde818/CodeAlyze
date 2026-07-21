from math import pi
K, N = map(int, input().split())
A = list(map(int, input().split()))
D = [0 for i in range(N)]
D[0] = abs(A[0] + (K - A[-1]))
for i in range(1, N):
  D[i] = abs(A[i] - A[i-1])
print(sum(D) - max(D))
