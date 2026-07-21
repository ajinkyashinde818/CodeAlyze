import sys

input = sys.stdin.readline

N = int(input())
A = [int(x) for x in input().split()]
B = [int(x) for x in input().split()]
C = [int(x) for x in input().split()]

total = sum(B)
for i in range(N - 1):
    if A[i] == A[i + 1] - 1:
        total += C[A[i] - 1]

print(total)
