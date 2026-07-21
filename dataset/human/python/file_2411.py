import itertools
d,g=map(int,input().split())
p=[]
c=[]
for i in range(d):
    p1,c1=map(int,input().split())
    p.append(p1)
    c.append(c1//100)
n=list(itertools.permutations(list(range(1,d+1))))
ans=1024
g//=100
for i in range(len(n)):
    cnt=g
    cnt2=0
    for j in range(d):
        num3=n[i][j]
        num4=num3*p[num3-1]
        if num4>=cnt:
            cnt2+=((cnt-1)//num3)+1
            break
        elif num4+c[num3-1]>=cnt:
            cnt2+=p[num3-1]
            break
        else:
            cnt-=num4+c[num3-1]
            cnt2+=p[num3-1]
    ans=min(ans,cnt2)
print(ans)
