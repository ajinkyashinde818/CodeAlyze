def solve():
    inf = 1 << 60
    D, G = map(int, input().split())
    p = []
    c = []
    for i in range(D):
        pi, ci = map(int, input().split())
        p.append(pi)
        c.append(ci)

    bitD = 1 << D
    min_cnt = inf
    for b in range(bitD):
        sc = 0
        cnt = 0
        for i in range(D):
            if (b & (1 << i)) != 0:
                sc += (i + 1) * 100 * p[i] + c[i]
                cnt += p[i]
        if sc < G:
            for i in range(D-1,-1,-1):
                if (b & (1 << i)) == 0:
                    unit = (i + 1) * 100
                    cnt2 = min((G - sc + (unit - 1)) // unit, p[i] - 1)
                    sc += cnt2 * unit
                    cnt += cnt2
                    break
        if sc >= G:
            min_cnt = min(min_cnt, cnt)

    return min_cnt

print(solve())
