from itertools import permutations

D, G = map(int, input().split())
PC = []
for _ in range(D):
    p, c = map(int, input().split())
    PC.append((p, c))

ans = sum(p for p, _ in PC)
for ids in permutations(range(D)):
    score = 0
    num = 0
    for i in ids:
        p, c = PC[i]
        if score + (i + 1) * 100 * p + c < G:
            score += (i + 1) * 100 * p + c
            num += p
        else:
            for j in range(p):
                score += (i + 1) * 100
                num += 1
                if G <= score:
                    ans = min(ans, num)
                    break
            else:
                score += c
                if G <= score:
                    ans = min(ans, num)
        if G <= score:
            break
print(ans)
