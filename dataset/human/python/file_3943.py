N = int(input())
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
c = collections.Counter(prime_factorize(N))
sosu = list(c.values())
answer = 0
for i in range(len(sosu)):
    if sosu[i]==1:
        answer += 1
    else:
        answer += int(-1/2+((1+8*(sosu[i]))**(1/2))/2)
print(answer)
