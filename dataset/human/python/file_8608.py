import sys
input = sys.stdin.readline
K, N = list(map(int, input().split()))
A = list(map(int, input().split()))

A.append(K + A[0])
B = []
for i in range(N):
  B.append(A[i+1] - A[i])
print(K-max(B))
