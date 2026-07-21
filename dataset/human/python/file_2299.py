from itertools import product
d, g = list(map(int, input().split()))
pl = [0] * d
cl = [0] * d
for i in range(d):
    pl[i], cl[i] = map(int, input().split())
INF = float("inf")
ans = INF
for bit in product([0, 1], repeat=d):
    anss = 0
    score = 0
    I = 0
    for i in range(d):
        if bit[i] == 0:
            I = i
        else:
            score += pl[i]*100*(i+1)
            score += cl[i]
            anss += pl[i]

    for _ in range(pl[I]):
        if score >= g:
            ans = min(ans, anss)
            break
        else:
            score += (I+1)*100
            anss += 1
    if score >= g:
        ans = min(ans, anss)

print(ans)
