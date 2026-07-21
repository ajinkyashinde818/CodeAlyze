import sys

N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
C = list(map(int, input().split()))

Satis = 0

for i in range(N):

    Satis += B[A[i] - 1]

    if 0 < i:
        if A[i - 1] + 1 == A[i]:
            Satis += C[A[i - 1] - 1]

print(Satis)
