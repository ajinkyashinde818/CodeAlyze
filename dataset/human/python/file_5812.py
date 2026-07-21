from sys import stdin
N = int(stdin.readline().rstrip())
A = [int(x) for x in stdin.readline().rstrip().split()]
B = [int(x) for x in stdin.readline().rstrip().split()]
C = [int(x) for x in stdin.readline().rstrip().split()]

ans = 0
for i in A:
    ans += B[i-1]
for j in range(0,N-1):
    if A[j+1] - A[j] == 1:
        ans += C[A[j]-1]
print(ans)
