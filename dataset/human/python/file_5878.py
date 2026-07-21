from sys import stdin

n = int(stdin.readline().rstrip())
A = [int(x) for x in stdin.readline().rstrip().split()]
B = [int(x) for x in stdin.readline().rstrip().split()]
C = [int(x) for x in stdin.readline().rstrip().split()]

ans = sum(B)

for i in range(n-1):
    if A[i+1] == A[i] + 1:
        ans += C[A[i]-1]

print(ans)
