def solve(D, G):
    p, c = [], []

    for _ in range(D):
        _p, _c = map(int, input().split())
        p.append(_p)
        c.append(_c)

    each_total = []
    ans = float('inf')

    for i in range(D):
        each_total.append((p[i])*(i+1)*100+c[i])

    for j in range(1 << D):
        total_ope, total_score = 0, 0
        for k in range(D):
            if j >> k & 1:
                total_score += each_total[k]
                total_ope += p[k]
            else:
                solve_half = k

        for _ in range(p[solve_half]-1):
            if total_score >= G:
                break
            else:
                total_score += 100*(solve_half+1)
                total_ope += 1
        if total_score < G:
            continue

        ans = min(ans, total_ope)

    return ans


if __name__ == '__main__':
    D, G = map(int, input().split())
    print(solve(D, G))
