from itertools import product

D, G = map(int, input().split())
pc = [tuple(map(int, input().split())) for _ in range(D)]

ans = 10**18
for pair in product(range(2), repeat=D):
    score = 0
    cnt = 0
    for i, solve in enumerate(pair):
        p, c = pc[i]
        if solve:  # ポイント合算
            score += (i + 1) * 100 * p + c
            cnt += p

    if score >= G:
        ans = min(ans, cnt)
        continue

    rest = G - score
    plus = 10**9
    for i, solve in enumerate(pair):
        j = 100*(i+1)
        p, _ = pc[i]
        if not solve:
            need = (rest + j - 1) // j
            if need <= p:
                plus = min(plus, need)
    ans = min(ans, cnt + plus)

print(ans)
