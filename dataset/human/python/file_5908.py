import sys

sr = lambda: sys.stdin.readline().rstrip()
ir = lambda: int(sr())
lr = lambda: list(map(int, sr().split()))

N = ir()
A = lr()
B = lr()
C = lr()
temp = 0
answer = 0
for i in range(N):
    answer += B[A[i] - 1]
    if 0 < i and A[i] - A[i-1] == 1:
        if A[i] - 1 <= N-1:
            answer += C[A[i-1] - 1]

print(answer)
