n = int(input())
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
c = collections.Counter(prime_factorize(n))

ans = 0
for i in c:
    tmp = c[i]
    num = 1
    while tmp >= 0:
        tmp -= num 
        if tmp >= 0:
            ans += 1
        num += 1
        
print(ans)
