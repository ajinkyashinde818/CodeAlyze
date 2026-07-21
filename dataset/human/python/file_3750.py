N=int(input())
def factorize(n):
    b = 2
    fct = []
    while b * b <= n:
        while n % b == 0:
            n //= b
            fct.append(b)
        b = b + 1
    if n > 1:
        fct.append(n)
    return fct

bunkai=factorize(N)
blist=list(set(bunkai))

ans=0
for i in blist:
    tmp=bunkai.count(i)
    for p in range(1,50):
        if tmp>=p:
            ans+=1
            tmp-=p
        else:
            break
print(ans)
