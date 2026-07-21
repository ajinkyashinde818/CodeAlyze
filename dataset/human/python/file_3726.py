from math import floor,sqrt
def prime(n):
    a = []
    d={}
    while n % 2 == 0:
        try:
            d[2]+=1
        except:
            d[2]=1
            a.append(2)
        n //= 2
    f = 3
    while f * f <= n:
        if n % f == 0:
            try:
                d[f]+=1
            except:
                d[f]=1
                a.append(f)
            n //= f
        else:
            f += 2
    if n != 1:
        try:
            d[n]+=1
        except:
            d[n]=1
            a.append(n)
    return a,d
n=int(input())
a,d=prime(n)
ans=0
for i in range(len(a)):
    k=floor(sqrt(2*d[a[i]]))
    if k*(k+1)//2>d[a[i]]:
        k-=1
    ans+=k
print(ans)
