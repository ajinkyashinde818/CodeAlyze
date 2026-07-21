import numpy as np
N=int(input())
A = list(map(int, input().split()))


dp =[[0,0] for _ in range(len(A)+1) ]

dp[0][0] = A[0]
dp[0][1] = -A[0]

max_value= sum(A)
for y in range(len(A)-1):
    dp[y+1][0] = max(dp[y][0]+A[y+1], dp[y][1]-A[y+1])
    dp[y+1][1] = max(dp[y][1]+A[y+1], dp[y][0]-A[y+1]) 

print(dp[N-1][0])
