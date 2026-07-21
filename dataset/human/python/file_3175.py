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

number=int(input())
consequence=factorize(number)
c=list(set(consequence))

ans=0

for i in range(len(c)):
    Count=consequence.count(c[i])
    d=f=1
    while Count >= d:
        f +=1
        d +=f
        ans +=1

print(ans)
