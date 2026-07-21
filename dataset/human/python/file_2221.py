from itertools import product
D, G = map(int, input().split())
P, C = zip(*[map(int, input().split()) for _ in range(D)])
INF = 10**18
ans = INF
for bit in product((0, 1), repeat=D):
    p = list(P)
    cnt = 0
    score = 0
    for i in range(D):
        if bit[i]:
            score += C[i]
            score += P[i]*100*(i+1)
            cnt += P[i]
            p[i] = 0
 
    if score+sum(p[i]*100*(i+1) for i in range(D)) < G:
        continue
 
    idx = D-1
    while score < G:
        while not p[idx]:
            idx -= 1
        score += 100*(idx+1)
        p[idx] -= 1
        cnt += 1
    if cnt < ans:
        ans = cnt
print(ans)
