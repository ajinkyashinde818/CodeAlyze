import itertools,math

D, G = map(int, input().split())
Q = []
for _ in range(D):
    Q.append(tuple(map(int, input().split())))

ans = 1000  # 制約上の最大値
for t in itertools.product([0, 1], repeat=D):
    score = sum(t[i] * (Q[i][0] * 100 * (i + 1) + Q[i][1]) for i in range(D))
    ans_tmp = sum(t[i] * Q[i][0] for i in range(D))
    if score < G:
        p = D - 1
        while t[p]:
            p -= 1
        addition_q = math.ceil((G - score) / (100 * (p + 1)))
        if addition_q >= Q[p][0]:
            continue
        ans_tmp += addition_q
    ans = min(ans, ans_tmp)
print(ans)
