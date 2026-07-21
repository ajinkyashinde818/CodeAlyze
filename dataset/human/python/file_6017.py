import sys
input = sys.stdin.readline

N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
C = list(map(int, input().split()))
ans = 0
before = 0.5
for i in range(N):
    now = A[i] - 1
    ans += B[now]
    if now == before + 1:
        ans += C[before]
    before = now

print(ans)
