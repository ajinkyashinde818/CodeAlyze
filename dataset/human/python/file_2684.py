from itertools import product
 
D, G = map(int, input().split())
score = []
for i in range(D):
    p, c = map(int, input().split())
    s = (i + 1) * 100
    score.append([s, p, c, s * p + c])
 
ans = float('inf')
for ptn in product([0, 1], repeat=D):
    total = 0
    cnt = 0
    for i in range(D):
        total += score[i][3] * ptn[i]
        cnt += score[i][1] * ptn[i]
 
    if 0 in ptn[::-1]:
        i = D - 1 - ptn[::-1].index(0)
        x = score[i]
    else:
        x = score[-1]
 
    for i in range(x[1]):
        if total >= G:
            break
        total += x[0]
        cnt += 1
 
    if total < G:
        cnt = float('inf')
    ans = min(ans, cnt)
print(ans)
