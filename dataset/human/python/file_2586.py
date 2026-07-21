import math
d, g = map(int, input().split())
p = [0 for _ in range(d+1)]
c = [0 for _ in range(d+1)]
ans = 10 ** 10
for i in range(d):
    pi, ci = map(int, input().split())
    p[i+1] = pi
    c[i+1] = ci     
for bit in range ( 1 << d):
    score = 0
    cnt = 0
    tokanai_saidai = 0
    for i in range(d):
        if bit & (1 << i):
            score += p[i+1] * 100 * (i+1) + c[i+1]
            cnt += p[i+1]
        else:
            tokanai_saidai = i + 1
    if score >= g:
        if cnt < ans:
            ans = cnt
    else:
        nokori_score = g - score
        if nokori_score < 100 * (tokanai_saidai) * p[tokanai_saidai]:
            cnt += math.ceil(nokori_score / (100 * tokanai_saidai))
            if cnt < ans:
                ans = cnt 
print(ans)
