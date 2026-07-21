import math
D, G = map(int,input().split())
p = [0] * D
c = [0] * D
for i in range(D):
    p[i], c[i] = map(int, input().split())
ans = 10**10
for i in range(2**D):
    rest = G
    problems = 0
    for j in range(D):
        if i & 2**(D-j-1):
            problems += p[j]
            rest -= p[j] * (j+1) * 100 + c[j]
        if rest <= 0:
            break
    for j in reversed(range(D)):
        if rest <= 0:
            break
        if i & 2**(D-j-1):
            continue
        add_problems = min(p[j] - 1, math.ceil(rest//((j+1)*100)))
        problems += add_problems
        rest  -= add_problems * (j+1) * 100
    if rest <= 0:
        ans = min(ans, problems)
print(ans)
