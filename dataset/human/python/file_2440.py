import math

D, G = map(int, input().split())
P = []
C = []
for _ in range(D):
    p, c = map(int, input().split())
    P.append(p)
    C.append(c)

ans = float('inf')
for bit in range(1 << D):
    count = 0
    num = 0
    rest_num = set(range(1, D+1))

    for i in range(D):
        if bit & (1 << i):
            num += P[i] * (i+1) * 100 + C[i]
            count += P[i]
            rest_num.discard(i+1)

    if num < G:
        max_num = max(rest_num)
        n = min(P[max_num-1], math.ceil((G-num)/(max_num*100)))
        count += n
        num += n * max_num * 100

    if num >= G:
        ans = min(ans, count)

print(ans)
