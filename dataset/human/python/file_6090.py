def makelist(n, m):
    return [[0 for _ in range(m)] for _ in range(n)]

N = int(input())
A = [0] + list(map(int, input().split()))
B = [0] + list(map(int, input().split()))
C = [0] + list(map(int, input().split()))

pre = -1
ans = 0
for a in A[1:]:
    now = B[a]
    ans += now
    if a - 1 == pre:
        ans += C[pre]
    pre = a
print(ans)
