def read():
    N = input().strip()
    return N,


def solve(N, INF=1000000):
    L = len(N)
    N = list(reversed("0" + N))
    dp0 = [0 for i in range(L + 1)]
    dp1 = [0 for i in range(L + 1)]
    dp1[0] = INF
    for i in range(L):
        x = int(N[i])
        dp0[i + 1] = min(dp0[i] + x, dp1[i] + x)
        dp1[i + 1] = min(dp0[i] + 1 + (10 - x), dp1[i] + 1 + (10 - x) - 2)
    return min(dp0[-1], dp1[-1])


if __name__ == '__main__':
    inputs = read()
    print("{}".format(solve(*inputs)))
