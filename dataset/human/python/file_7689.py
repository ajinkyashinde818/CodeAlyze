from itertools import chain

while True:
    n = int(input())
    if not n:
        break
    dp = [[0]*(n+1) for _ in [0]*(n+1)]
    for y, (l_u, l_c) in enumerate(zip(dp, dp[1:]), start=1):
        for x, (c, ul, u, left) in enumerate(zip(input(), l_u, l_u[1:], l_c), start=1):
            dp[y][x] = min(ul, u, left)+1 if c == "." else 0

    print(max(chain.from_iterable(dp)))
