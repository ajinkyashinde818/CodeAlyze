import collections
def prime_factorize(n):
    a = []
    while n % 2 == 0:
        a.append(2)
        n //= 2
    f = 3
    while f * f <= n:
        if n % f == 0:
            a.append(f)
            n //= f
        else:
            f += 2
    if n != 1:
        a.append(n)
    return a



c = collections.Counter(prime_factorize(int(input())))
ans=0
l=list(c.values())

for i in l:
    j=int(i)
    a=1
    while j>0:
        if j>=a:
            j-=a
            ans+=1
            a+=1
        else:
            break
#print(l)
print(ans)
