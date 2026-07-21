import sys
INF = 1 << 60
MOD = 10**9 + 7 # 998244353
sys.setrecursionlimit(2147483647)
input = lambda:sys.stdin.readline().rstrip()
def resolve():
    n, k = map(int, input().split())
    f = list(map(lambda x : int(x) - 1, input().split()))
    step = [-1] * n
    step[0] = 0
    now = 0
    while step[f[now]] == -1:
        step[f[now]] = step[now] + 1
        now = f[now]
        if step[now] == k:
            print(now + 1)
            return

    k -= step[now]
    loop = step[now] - step[f[now]] + 1
    k %= loop
    for _ in range(k):
        now = f[now]
    print(now + 1)
resolve()
