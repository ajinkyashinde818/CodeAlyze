import sys
stdin = sys.stdin

ns = lambda: stdin.readline().rstrip()
ni = lambda: int(stdin.readline().rstrip())
nm = lambda: map(int, stdin.readline().split())
nl = lambda: list(map(int, stdin.readline().split()))

N=int(input())
A=nl()
B=nl()
C=nl()
sum=0

sum+=B[A[0]-1]
for i in range(1,N):
    option= C[A[i-1]-1] if (A[i]==A[i-1]+1) else 0
    sum+=B[A[i]-1]+option

print(sum)
