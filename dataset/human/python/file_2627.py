import sys
d,g=map(int,input().split())
p=[0]*d
c=[0]*d
for i in range(d):
    p[i],c[i]=map(int,input().split())
ans=float('inf')
for i in range(1<<d):
    su=0
    left=-1
    cnt=0
    for j in range(d):
        if (i>>j)&1:
            su+=p[j]*(j+1)*100
            su+=c[j]
            cnt+=p[j]
        else:
            left=max(left,j)
    if su<g:
        for j in range(p[left]):
            su+=100*(left+1)
            cnt+=1
            if su>=g:
                break
    if su>=g:
        ans=min(ans,cnt)
print(ans)
