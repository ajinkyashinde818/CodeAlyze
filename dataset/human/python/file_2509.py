import itertools

D, G = map(int, input().split())
P = [0 for _ in range(D)]
C = [0 for _ in range(D)]
for i in range(D):
    p, c = map(int, input().split())
    P[i] = p
    C[i] = c

ans = 10 ** 10
for mask in itertools.product((0, 1), repeat=D):
    myscore = 0
    soloved_num = 0
    incomplete_index = 0
    for i, j in enumerate(mask):
        if j == 0:
            incomplete_index = i
        else:
            myscore += P[i] * (i + 1) * 100 + C[i]
            soloved_num += P[i]
    if myscore < G:
        for n in range(P[incomplete_index]):
            myscore += (incomplete_index + 1) * 100
            soloved_num += 1
            if myscore >= G:
                break
    if myscore >= G:
        ans = min(ans, soloved_num)

print(ans)
