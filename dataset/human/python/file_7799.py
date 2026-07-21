import sys

sr = lambda: sys.stdin.readline().rstrip()
ir = lambda: int(sr())
lr = lambda: list(map(int, sr().split()))

N, K, S = lr()
INF = 10 ** 9
if S < INF:
    answer = [S] * K + [S+1] * (N-K)
else:
    answer = [S] * K + [1] * (N-K)    

print(*answer)
