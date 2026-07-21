from copy import deepcopy
n = str(input().rstrip())

def solve1(n):
    ans = 0

    a = list(map(int, list(n)))
    a = a[::-1]
    a.append(0)
    for i in range(len(a) - 1):
        c = a[i]
        if c < 5:
            ans += c
        else:
            if c == 5 and a[i+1] < 5:
                ans += 5
            else:
                a[i+1] += 1
                ans += 10 - c
    ans += n_list[-1]

    print(ans)

def solve2(n):
    INF = 10**9
    n = n[::-1]
    n += '0'
    n_len = len(n)
    dp = [INF for _ in range(2)]
    dp[0] = 0

    for i in range(n_len):
        pre_dp = deepcopy(dp)
        dp = [INF, INF]
        for j in range(2):
            x = int(n[i])
            x += j
            if x < 10:
                dp[0] = min(dp[0], pre_dp[j]+x)
            if x > 0:
                dp[1] = min(dp[1], pre_dp[j]+(10-x))

    print(dp[0])
solve2(n)
