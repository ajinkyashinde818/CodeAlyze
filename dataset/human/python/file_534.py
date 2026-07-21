def sub():
    N, As = [input() for _ in range(2)]
    N = int(N)
    As = [int(e) for e in As.split(" ")]

    dp = {(-1, 0): 0, (-1, 1): -1e10}
    for i in range(0, N):
        dp[(i, 0)] = max(dp[(i - 1, 0)] + As[i], dp[(i - 1, 1)] - As[i])
        dp[(i, 1)] = max(dp[(i - 1, 0)] - As[i], dp[(i - 1, 1)] + As[i])
    print("{}".format(dp[(N - 1, 0)]))


sub()
