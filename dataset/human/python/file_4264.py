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
  
import collections
N = int(input())

c = collections.Counter(prime_factorize(N))

ans = 0
for j in c:
    for i in range(1,c[j]+1):
        if c[j] == 1:
            ans += 1
        elif i*(i+1)<= 2*c[j] < (i+1)*(i+2):
            ans += i

print(ans)
