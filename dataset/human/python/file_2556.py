from itertools import combinations
D, G = map(int, input().split())
G = G // 100
ns = [0] * (D + 1)
cs = [0] * (D + 1)
for i in range(1, D + 1):
    n, c = map(int, input().split())
    ns[i] = n
    cs[i] = c // 100

ans = sum(ns)
for partialsn in range(1, D + 1):
    for partials in combinations(range(1, D + 1), partialsn):
        sumn = 0
        rp = G
        for i in range(1, D + 1):
            if not i in partials:
                sumn += ns[i]
                rp -= i * ns[i] + cs[i]
        if rp > 0:
            for i in sorted(partials, reverse=True):
                n = ns[i] - 1
                if rp <= i * n:
                    n = rp // i
                    if rp % i != 0:
                        n += 1
                sumn += n
                rp -= i * n
                if rp <= 0:
                    break
        if rp <= 0:
            if sumn < ans:
                ans = sumn
print(ans)
