import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline
inpl = lambda: list(map(int,input().split()))
N = int(input())
A = inpl()
B = inpl()
C = inpl()
prev = -1
ans = sum(B)
for i in range(N):
    if A[i] == prev + 1:
        ans += C[prev-1]
    prev = A[i]
print(ans)
