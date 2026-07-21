import copy
D,G = map(int, input().split())
m = [0]*D
for i in range(D):
    m[i] = list(map(int,input().split()))
score = 0
count = 0
ans = 0

for i in range(1 << D):
    l = copy.deepcopy(m)
    score = 0
    count = 0
    for j in range(D):
        if i >> j & 1 == 1:
            score += l[j][1] + l[j][0]*(j+1)*100
            count += l[j][0]
            l[j][0] = 0
    k = D-1
    while score < G:
        if l[k][0] > 1:
            l[k][0] -= 1
            score += 100*(k+1)
            count += 1
        else:
            k -= 1
            if k < 0:
                break
    if score >= G:
        if ans > count or ans == 0:
            ans = count

print(ans)
