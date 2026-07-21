import math

MAX_INT = 1001
(d, g) = list(map(int, input().split()))
g = g // 100
arr = [[0, 0] for i in range(d+1)]
for i in range(1, d+1):
    tmp = list(map(int, input().split()))
    arr[i][0] = tmp[0]
    arr[i][1] = tmp[1] // 100

res = MAX_INT
dp = [[MAX_INT for i in range(g+1)] for k in range(d+1)]
for diff in range(1, d+1):
    e = arr[diff]
    for score in range(1, g+1):
        if score / diff <= e[0]:
            dp[diff][score] = math.ceil(score/diff)
        elif score <= diff * e[0] + e[1]:
            dp[diff][score] = e[0]
        else:
            dp[diff][score] = dp[diff-1][score - (diff * e[0] + e[1])] + e[0]
        dp[diff][score] = min(dp[diff][score], dp[diff-1][score])
# for diff in range(1, d+1):
#     print(*dp[diff])

print(dp[d][g])
