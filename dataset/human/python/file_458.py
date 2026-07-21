import numpy as np
import fractions

if __name__ == "__main__":
    N = int(input())
    A = list(map(int, input().split()))
    dp = {}
    dp[0, 0] = 0
    dp[0, 1] = -100000000000
    for i in range(1, N):
        dp[i, 0] = max(dp[i-1,0]+A[i-1], dp[i-1,1]-A[i-1])
        dp[i, 1] = max(dp[i-1,0]-A[i-1], dp[i-1,1]+A[i-1])
    print(max(dp[N-1,0]+A[N-1], dp[N-1,1]-A[N-1]))
