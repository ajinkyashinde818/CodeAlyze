from math import ceil
D,G=map(int,input().split())
p,c=[0]*D,[0]*D
for i in range(D):
    p[i],c[i]=map(int,input().split())

m=0
mondai=[]
for i in range(2**D,2**(D+1)):
    s=(bin(i))[3:]
    a,b=0,0
    for j in range(D):
        if s[j]=='1':
            a,b=a+p[j],b+100*(j+1)*p[j]+c[j]
        else:
            m=j
    if G<=b:
        mondai.append(a)
    if G-p[m]*100*(m+1)<b<G:
        ad=ceil((G-b)/(100*(m+1)))
        mondai.append((a+ad))
print(min(mondai))
