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

pf = prime_factorize(N)
setpf = set(pf)

import collections
cpf = collections.Counter(pf)

cnt = 0
for i in setpf:
    tmp = cpf[i]
    for j in range(1,50):
        tmp -= j
        if tmp < 0:
            break
        else:
            cnt += 1
print(cnt)
