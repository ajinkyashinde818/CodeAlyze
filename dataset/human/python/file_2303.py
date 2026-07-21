import itertools as ite
import math
d,g=list(map(int,input().split()))
question=[]
for i in range(d):
    question.append(list(map(int,input().split())))

ans=1000
for pattarn in ite.product([0,1],repeat=d):
    score=0
    max_notsolve=-1
    solvednum=0
    for i in range(d):
        if pattarn[i]==1:
            score += question[i][0]*(i+1)*100+question[i][1]
            solvednum+=question[i][0]
        else:
            max_notsolve=max(max_notsolve,i)
    if score >= g:
        ans=min(ans,solvednum)
    else:
        if max_notsolve==-1:
            continue
        elif g-score > question[max_notsolve][0]*(max_notsolve+1)*100:
            continue
        else:
            solvednum+=math.ceil((g-score)/((max_notsolve+1)*100))
    ans=min(ans,solvednum)
print(ans)
