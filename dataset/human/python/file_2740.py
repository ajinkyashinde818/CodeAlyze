import itertools
D, G = map(int, input().split())
p = [0] * D
c = [0] * D
pc = [0] * D
for i in range(D):
    p[i], c[i] = map(int, input().split())

l = list(itertools.product(range(2), repeat=D))

comp = []
for i in range(len(l)-1):
    score = 0
    count = 0
    m = -100
    for j in range(D):
        if l[i][j] == 1:
            score += (j+1) * 100 * p[j] + c[j]
            count += p[j]
        elif l[i][j] == 0:
            m = max(m, j)
    tmp = [score, count]
    comp.append(tmp)
    for j in range(p[m]-1):
        score += (m+1) * 100 * 1
        count += 1
        tmp = [score, count]
        comp.append(tmp)

score = 0
count = 0
for i in range(D):
    score += (i+1) * 100 * p[i] + c[i]
    count += p[i]
tmp = [score, count]
comp.append(tmp)    

#print(comp)

ans = []
for i in range(len(comp)):
    if comp[i][0] >= G:
        ans.append(comp[i][1])

ans = min(ans)
print(ans)
