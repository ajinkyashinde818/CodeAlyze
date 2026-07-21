import sys, collections
sys.setrecursionlimit(10000)
R, G, B, N = [int(_) for _ in input().split()]

cd = collections.defaultdict
memo = cd(lambda: cd(int))


def dfs(res, color):
    if res < 0:
        return 0
    elif res == 0:
        return 1
    elif memo[res][color] == 0:
        if color == 0:
            memo[res][color] = dfs(res - R, 0) + dfs(res - G, 1) + dfs(
                res - B, 2)
        elif color == 1:
            memo[res][color] = dfs(res - G, 1) + dfs(res - B, 2)
        elif color == 2:
            memo[res][color] = dfs(res - B, 2)
    return memo[res][color]


print(dfs(N, 0))
