import itertools as it
D, G = map(int, input().split())
P, C = [], []
for _ in range(D):
    p, c = map(int, input().split())
    P.append(p)
    C.append(c)
A = it.permutations([i for i in range(D)])
ans = 10**9
for a in A:
    S, i, sub_ans = 0, 0, 0
    while 1:
        if S + (a[i] + 1) * 100 * P[a[i]] < G:
            S += (a[i] + 1) * 100 * P[a[i]]
            sub_ans += P[a[i]]
        else:
            x = (G - S) // ((a[i] + 1) * 100)
            if S + (a[i] + 1) * 100 * x < G:
                x += 1
            sub_ans += x
            S += (a[i] + 1) * 100 * x
        S += C[a[i]]
        if S >= G:
            if sub_ans < ans:
                ans = sub_ans
            break
        i += 1
print(ans)
