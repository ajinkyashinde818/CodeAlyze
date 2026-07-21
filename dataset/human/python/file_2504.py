import math

D, G = map(int, input().split())
prob = [list(map(int, input().split())) for i in range(D)]
tmp = 100*10

for i in range(1<<D):
    grade = 0
    cnt = 0
    judge = list(range(1, D+1))

    for j in range(D):
        if (i>>j & 1):
            grade += (100*(j+1)*prob[j][0] + prob[j][1])
            cnt += prob[j][0]
            judge[j] = 0

    if grade >= G and tmp > cnt:
        tmp = cnt
        
    num = prob[(max(judge))-1][0]

    if G > grade and num > math.ceil((G - grade)/(max(judge)*100)):
        cnt += math.ceil((G - grade)/(max(judge)*100)) 
        if tmp > cnt:
            tmp = cnt

print(tmp)
