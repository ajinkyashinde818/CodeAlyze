import itertools
D, G = [int(_) for _ in input().split()]
SPC = [[100 * (i + 1)] + [int(_) for _ in input().split()]
       for i in range(D)][::-1]
ans = 10**10
for i in range(D + 1):
    completes = set(itertools.combinations(range(D), i))
    for complete in completes:
        incomplete = sorted(set(range(D)) - set(complete))
        score = 0
        cnt = 0
        f = 0
        for j in complete:
            s, p, c = SPC[j]
            score += s * p + c
            cnt += p
        for j in incomplete:
            if score >= G:
                break
            s, p, c = SPC[j]
            d = min(p - 1, 1 + (G - score - 1) // s)
            score += s * d
            cnt += d
        if score >= G:
            ans = min(ans, cnt)
print(ans)
