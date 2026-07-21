import math
D, G = map(int, input().split())
P, C = [], []
for _ in range(D):
    p, c = map(int, input().split())
    P.append(p)
    C.append(c)

ans = float('inf')
for i in range(2**D):
    score = 0
    cnt = 0
    max_zero = 0
    # print(bin(i))
    # b = bin(i)[2:][::-1]
    # print(b)
    # for j, c in enumerate(b):
    for j in range(D):
        x = (i >> j) & 1
        # x = int(c)
        if x == 1:
            cnt += P[j]
            score += 100 * (j + 1) * P[j] + C[j]
        else:
            max_zero = j
    if G <= score:
        ans = min(ans, cnt)
    else:
        diff = G - score
        base = 100 * (max_zero + 1)
        if P[max_zero] <= math.ceil(diff / base):
            continue
        else:
            cnt += math.ceil(diff / base)
            ans = min(ans, cnt)
print(ans)
