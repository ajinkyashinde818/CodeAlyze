from math import ceil
D,G=map(int,input().split())
P=[]
C=[]
R=[]
for i in range(D):
    p,c=map(int,input().split())
    P.append(p)
    C.append(c)
    R.append((i+1)*100*p+c)
bit=2**D
ans=10**19
for i in range(bit):
    i=bin(i)[2:].zfill(D)
    su=0
    num=0
    k=-1
    for j in range(D):
        k=int(i[j])
        su+=k*R[j]
        num+=k*P[j]
        if k==0:
            t=j
    if G<=su:
        ans=min(ans,num)
        continue
    if k==-1:
        continue
    if  ceil((G-su)/((t+1)*100))<P[t]:
        ans=min(ans,num+ceil((G-su)/((t+1)*100)))
print(ans)
