import math

def f(i, s):
    global ans
    if s.count(1) > 1:
        return
    if i == d:
        score = 0
        cnt = 0
        notcomp = -1
        for k in range(d):
            if s[k] == 1:
                notcomp = k
            if s[k] == 2:
                score += comp[k]
                cnt += x[k][0]
        if g <= score:
            ans = min(ans, cnt)
        elif not notcomp == -1:
            r = g - score
            if r <= comp[notcomp]:
                cnt += min(math.ceil(r / ((notcomp + 1) * 100)), x[notcomp][0])
                ans = min(ans, cnt)
        return
    for j in range(3):
        s[i] = j
        f(i + 1, s)

d, g = map(int, input().split())
x = [list(map(int, input().split())) for _ in range(d)]
comp = [x[i][0] * 100 * (i + 1) + x[i][1] for i in range(d)]
s = [0] * d
ans = pow(10, 3)
f(0, s)
print(ans)
