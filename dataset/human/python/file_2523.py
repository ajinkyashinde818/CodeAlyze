import itertools
D,G=map(int,input().split())
p=[0 for i in range(D)]
c=[0 for i in range(D)]
for i in range(D):
    p[i],c[i]=map(int,input().split())

S=list(itertools.product(range(2),repeat=D))
ans=sum(p)
for seq in S:
    score=0
    prove=0
    for i in range(D):
        if seq[i]==1:
            score+=(p[i]*100*(i+1)+c[i])
            prove+=p[i]
    if score>=G:
        if ans>prove:
            ans=prove
        continue
    j=-1
    for i in range(D):
        if seq[i]==0:
            j=i
    for k in range(p[j]):
        prove+=1
        score+=100*(j+1)
        if G<=score:
            break
    if G>score:
        continue
    if ans>prove:
        ans=prove
print(ans)
