import math
d,g=map(int,input().split())
p=[]
p_=[]
c=[]
ans=float('inf')
for i in range(d):
    pi,ci=map(int,input().split())
    p.append(pi)
    p_.append(pi)
    c.append(ci)
for i in range(2**d):
    s_bit=[int(x) for x in list(format(i,'b'))]
    point=0
    number=0
    for j in range(len(s_bit)):
        point+=s_bit[len(s_bit)-1-j]*100*(j+1)*p[j]+s_bit[len(s_bit)-1-j]*c[j]
        number+=s_bit[len(s_bit)-1-j]*p[j]
        p_[j]=p[j]-p[j]*s_bit[len(s_bit)-1-j]
    if point>=g:
        ans=min(ans,number)
    else:
        remain=g-point
        for j in range(d):
            if 100*(j+1)*p_[j]>=remain:
                k=math.ceil(remain/(100*(j+1)))
                ans=min(ans,number+k)
print(ans)
