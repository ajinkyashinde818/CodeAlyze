from collections import defaultdict
n=int(input())
d=defaultdict(int)

def factorization(m):
    temp = m
    f=True
    for i in range(2, int(-(-n**0.5//1))+1):
        t=str(temp)
        if temp%i==0:
            f=False
            cnt=0
            while temp%i==0:
                cnt+=1
                temp //= i
            d[i]=cnt
    if temp!=1:
        d[temp]=1

    return f
if n==1:
    print(0)
elif factorization(n):
    print(1)
else :
    count=0
    for key in d.keys():
        l=d[key]
        i=1
        while l>=i:
            l-=i
            i+=1
            count+=1
    print(count)
