def factorize(n):
    a=[]
    while n%2==0:
        a.append(2)
        n//=2
    f=3
    while f*f<=n:
        if n%f==0:
            a.append(f)
            n//=f
        else:
            f+=2
    if n!=1:
        a.append(n)
    return a

def ra(a):
    ll,l=[],1
    for i in range(len(a)-1):
        if a[i]==a[i+1]:
            l+=1
        else:
            ll.append(l)
            l=1
    ll.append(l)
    return ll

import bisect
n=int(input())
if n==1:
    print(0)
    exit()
a=ra(factorize(n))
b=0
c=[-1]
for i in range(100):
    c.append(i+c[-1])
c.pop(0)
for i in a:
    b+=bisect.bisect_left(c,i)-1
print(b)
