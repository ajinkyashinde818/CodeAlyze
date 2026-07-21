from sys import stdin

N = int(stdin.readline().rstrip())
A = [int(x) for x in stdin.readline().rstrip().split()]
B = [int(x) for x in stdin.readline().rstrip().split()]
C = [int(x) for x in stdin.readline().rstrip().split()]

ans = 0

for i in range(N):
    ans += B[A[i] - 1]
    if i >= 1 and A[i - 1] + 1 == A[i]:
        ans += C[A[i - 1] - 1]

print(ans)
