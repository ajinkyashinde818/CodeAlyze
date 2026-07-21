import sys
from collections import deque
sys.setrecursionlimit(200000)
input = sys.stdin.readline

N = int(input())
A = [int(v) - 1 for v in input().split()]
B = [int(v) for v in input().split()]
C = [int(v) for v in input().split()]

ans = 0
for v in A:
    ans += B[v]

for i in range(N - 1):
    if A[i] + 1 == A[i + 1]:
        ans += C[A[i]]

print(ans)
