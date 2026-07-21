def primefactorize(n) :
    res = []
    if n%2 == 0 :
        t = 0
        while n%2 == 0 :
            n //= 2
            t += 1
        res.append((2,t))
    for i in range(3, int(n**0.5)+1, 2) :
        if n%i != 0 :
            continue
        t = 0
        while n%i == 0 :
            n //= i
            t += 1
        res.append((i,t))
        if n == 1 :
            break
    if n != 1 :
        res.append((n,1))
    return res


N = int(input())
res = 0
for p, e in primefactorize(N) :
    i = 1
    while e >= i :
        res += 1
        e -= i
        i += 1
print(res)
