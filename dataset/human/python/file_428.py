import sys
from collections import deque
sys.setrecursionlimit(10**5)
input = sys.stdin.readline
MAX = 10**5+5
INF = 10**9

def resolve():
    n = int(input())
    a = [0]
    a.extend(list(map(int,input().split())))
    dp = [[0,0] for _ in range(n+1)]
    dp[0][1]=-INF
    for i in range(1,n+1):
        dp[i][0] = max(dp[i-1][0]+a[i],dp[i-1][1]-a[i])
        dp[i][1] = max(dp[i-1][0]-a[i],dp[i-1][1]+a[i])
    print(dp[n][0])

if __name__ == "__main__":
    resolve()
