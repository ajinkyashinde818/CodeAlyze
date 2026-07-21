def solve():
    K, N = map(int,input().split())
    An = list(map(int,input().split()))
    dsum = 0
    dmax = 0

    for i in range(N):
        if i == 0:
            d = An[i] + K - An[N-1]
        else:
            d = An[i] - An[i-1]
        if d > dmax:
            dmax = d
        dsum += d
    print(dsum-dmax)

solve()
