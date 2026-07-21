import sys
input = sys.stdin.buffer.readline

K, N = map(int, input().split())
A = list(map(int, input().split()))

B = [A[0] + K - A[-1]]
for i in range(N - 1):
    B.append(A[i + 1] - A[i])

print(K - max(B))
