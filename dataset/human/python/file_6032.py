import sys
input = sys.stdin.readline
sys.setrecursionlimit(10 ** 7)

N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
C = list(map(int, input().split()))

ans = 0
tmp = -2
for i in range(N):
    if A[i]-1 == tmp + 1:
        ans += B[A[i]-1] + C[A[i]-2]
    else:
        ans += B[A[i]-1]
    tmp = A[i]-1
print(ans)
