import sys
sys.setrecursionlimit(10 ** 6)
input = sys.stdin.readline
K, N = [int(x) for x in input().strip().split()]
A = [int(x) for x in input().strip().split()]
A2 = [0] * len(A)
for i, a in enumerate(A[1:], start=1):
    A2[i] = A[i] - A[i-1]
A2.append(A[0] + K - A[-1])
print(K - max(A2))
