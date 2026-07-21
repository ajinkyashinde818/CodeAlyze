from itertools import product

D, G = map(int, input().split())
pc = [[int(x) for x in input().split()] for _ in range(D)]

C = [0] * D
for i in range(D):
    p, c = pc[i]
    C[i] = 100 * (i + 1) * p + c

ans = float('inf')
for ptn in product([0, 1], repeat=D):
    point, cnt = 0, 0
    for i in range(D):
        p, c = pc[i]
        cnt += p * ptn[i]
        point += C[i] * ptn[i]

    if 0 in ptn:
        index = D - 1 - ptn[::-1].index(0)
        p, _ = pc[index]
        for i in range(p):
            if point >= G:
                break            
            point += 100 * (index + 1)
            cnt += 1

    if point >= G:
        ans = min(ans, cnt)
print(ans)
