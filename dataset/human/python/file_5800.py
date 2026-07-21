import sys
def LI(): return list(map(int, sys.stdin.readline().split()))

N = int(input())
A = LI()
B = LI()
C = LI()

res = 0
for i in range(N):
    res += B[A[i] - 1]
    if i < N - 1 and A[i + 1] == A[i] + 1:
        res += C[A[i] - 1]

print(res)
