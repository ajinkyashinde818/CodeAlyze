import sys
input = sys.stdin.readline

N = int(input())
A = list(map(int, input().split()))
n = N * (N + 1) // 2
s = sum(A)
if s % n != 0:
    print('NO')
    exit()
c = s // n
d = [A[(i + 1) % N] - A[i] for i in range(N)]
for i in range(N):
    if c < d[i] or (c - d[i]) % N != 0:
        print('NO')
        exit()
print('YES')
