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

from collections import Counter

n = int(input())
if n == 1:
    print(0)
else:
    a = prime_factorize(n)
    c = Counter(a)
    ans = 0
    for v in c.values():
        temp = 1
        while True:
            v -= temp
            if v >= 0:
                ans +=1
                temp += 1
            else:
                break
    print(ans)
