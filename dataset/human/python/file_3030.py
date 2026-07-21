from collections import Counter
def p(n):
    a=[]
    i=2
    while i*i<=n:
        while n%i==0:
            a.append(i)
            n//=i
        i+=1
    if n>1:
        a.append(n)
    return a
N=int(input())
c=Counter(p(N))
ans=0
for k,v in c.items():
    j=0
    for i in range(1,100000):
        j+=i
        if j>v:
            break
        ans+=1
print(ans)
