from sys import stdin
import math

N, K = list(map(int, stdin.readline().rstrip().split()))
A = list(map(int, stdin.readline().rstrip().split()))


A.append(N + A[0])

max_diff = 0

for i in range(K):
    max_diff = max(max_diff, A[i+1] - A[i])

print(N - max_diff)
