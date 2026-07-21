if __name__ == '__main__':
    N, K = map(int, input().split())
    g = {}
    for i, a in enumerate(list(map(int, input().split()))):
        g[i + 1] = a

    rs = [1, g[1]]
    pos = g[1]
    used = [False for _ in range(N)]
    used[0] = True
    roop_i = None
    while 1:
        rs.append(g[pos])
        used[pos - 1] = True
        pos = g[pos]
        if used[pos - 1] is True:
            roop_i = pos
            break

    idx1 = rs.index(roop_i)

    d1 = idx1
    d2 = len(rs) - idx1 - 1

    if K <= d1:
        print(rs[K])
    else:
        print(rs[(K - d1) % d2 + d1])
