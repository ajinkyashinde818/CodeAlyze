import sys
sr = lambda: sys.stdin.readline().rstrip()
ir = lambda: int(sr())
lr = lambda: list(map(int, sr().split()))
def resolve():
    K, N = lr()
    A = lr()
    ans = 0
    for i in range(N-1):
        ans = max(A[i+1]-A[i], ans)
    ans = max(K-A[N-1]+A[0], ans)
    print(K-ans)
resolve()
