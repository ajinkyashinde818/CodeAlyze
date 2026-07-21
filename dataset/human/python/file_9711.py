import sys
stdin = sys.stdin
sys.setrecursionlimit(10**6)
ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))
nn = lambda: list(stdin.readline().split())
ns = lambda: stdin.readline().rstrip()

n,k = na()
a = na()
dp = [-1]*n
dp[0] = 0
i = 1
now = 0
loop = -1
start = -1

while True:
    now = a[now]-1
    if i == k:
        print(now+1)
        exit()
    if dp[now] == -1:
        dp[now] = i
    else:
        loop = i - dp[now]
        start = dp[now]
        break
    i+=1

print(dp.index((k-start)%loop+start)+1)
