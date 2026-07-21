N=int(input())
ans=0
def prime_factorize(n):
    a = []
    count=0
    while n % 2 == 0:
        count+=1
        n //= 2
    if count!=0:a.append(count)
    f = 3
    count=0
    while f * f <= n:
        if n % f == 0:
            count+=1
            n //= f
        else:
            f += 2
            if count!=0:a.append(count)
            count=0
    if f==n:
        count+=1
        n=1
    if count!=0:a.append(count)
    if n != 1:
        a.append(1)
    return a
c = prime_factorize(N)
for i in range(len(c)):
    a=c[i]
    for j in range(1,c[i]+1):
        if a>=j:
            ans+=1
            a-=j
        else:
            break
print(ans)
