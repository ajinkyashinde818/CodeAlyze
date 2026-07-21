import sys
input = sys.stdin.readline
N = int(input())
A = [int(x) for x in input().split()]
B = [int(x) for x in input().split()]
C = [int(x) for x in input().split()]

ans = B[A[0]-1]
for i in range(1,N) :
    ans += B[A[i]-1]
    if A[i] - A[i-1] == 1 :
        ans += C[A[i-1]-1]

print(ans)
