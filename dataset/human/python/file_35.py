from fractions import gcd
r,g,b,n=map(int,input().split())
t=0
for i in range(0,(n-1)//r+2):
    d=n-r*i
    if d%gcd(g,b)==0:
        c=0
        for j in range(0,(d-1)//b+2):
            if (d-j*b)%g==0:
                c=1
                break
        if c==1:
            t+=(d-j*b)//(g*b//gcd(g,b))+1
print(t)
