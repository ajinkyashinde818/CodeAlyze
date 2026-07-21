import sys
stdin = sys.stdin
sys.setrecursionlimit(10 ** 7)

i_i = lambda: int(i_s())
i_l = lambda: list(map(int, stdin.readline().split()))
i_s = lambda: stdin.readline().rstrip()

K, N = i_l()
A = i_l()
A = A + [x + K for x in A]

ans = []
for i in range(N):
    tmp = A[N+i-1] - A[i]
    ans.append(tmp)

print(min(ans))
