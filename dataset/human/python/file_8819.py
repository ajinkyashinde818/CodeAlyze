import sys
readline = sys.stdin.readline

K, N = map(int, readline().split())
A = list(map(int, readline().split()))

A = [a % K for a in A]
A.sort()

b = [A[i + 1] - A[i] for i in range(len(A) - 1)]
b.append(A[0] + K - A[-1])

print(K - max(b))
