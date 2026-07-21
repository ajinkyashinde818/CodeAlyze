import sys
sys.setrecursionlimit(500000)
def input():
    return sys.stdin.readline()[:-1]

N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
C = list(map(int, input().split()))

ans = sum(B)

for k in range(N-1):
    if A[k+1] == A[k]+1:
        ans += C[A[k]-1]
print(ans)
