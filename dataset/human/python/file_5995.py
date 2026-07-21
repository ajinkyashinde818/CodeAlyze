from sys import stdin
N = int(stdin.readline().rstrip())
A = [int(_) for _ in stdin.readline().rstrip().split()]
B = [int(_) for _ in stdin.readline().rstrip().split()]
C = [int(_) for _ in stdin.readline().rstrip().split()]
ans = 0
ans += sum(B)
for i in range(N-1):
    if A[i+1] == A[i]+1:
        ans += C[A[i]-1]
print(ans)
