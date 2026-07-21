def m(g, ps):
    res = 0
    i = len(ps) - 1
    while g > 0 and i >= 0:
        if ps[i] > 0:
            g -= 100 * (i + 1)
            ps[i] -= 1
            res += 1
        else:
            i -= 1
    return res if g <= 0 else 1 << 30


def main():
    d, g = map(int, input().split())
    ps = [0] * d
    cs = [0] * d
    for i in range(d):
        ps[i], cs[i] = map(int, input().split())
    qs = [p - 1 for p in ps]
    res = m(g, qs)
    for i in range(1, 1 << d):
        qs = [p - 1 for p in ps]
        g0 = 0
        m0 = 0
        for j in range(d):
            if (i >> j) & 1:
                g0 += 100 * (j + 1) * ps[j] + cs[j]
                m0 += ps[j]
                qs[j] = 0
        if g0 < g:
            res = min(res, m0 + m(g - g0, qs))
        else:
            res = min(res, m0)
    print(res)


if __name__ == '__main__':
    main()
