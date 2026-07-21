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

N = int(input())

c = collections.Counter(prime_factorize(N))

output = 0
for k, v in c.items():
    num = 1
    cnt = 0
    while num <= v:
        cnt += 1
        v -= num
        num += 1
    output += cnt
    
print(output)
