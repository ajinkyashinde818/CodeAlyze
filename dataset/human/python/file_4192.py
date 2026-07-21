import math
def findFactors(n):
    now=n
    f=[]
    while now%2==0:
        now//=2
        f.append(2)
    p=3
    while p<=math.sqrt(n):
        while now%p==0:
            now//=p
            f.append(p)
        p+=2
        if now==1:
            break
    if now>math.sqrt(n):
        f.append(now)
    return f

C=[0]
for i in range(1,100):
    C.append(C[-1]+i)
    
n=int(input())
F=findFactors(n)

ans=0
now=0
cnt=0
for f in F:
    if now!=f:
        for c in range(1,90):
            if C[c]>cnt:
                break
        ans+=c-1
        now=f
        cnt=1
    else:
        cnt+=1
for c in range(1,100):
    if C[c]>cnt:
        break
ans+=c-1       
print(ans)
