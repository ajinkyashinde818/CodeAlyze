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

n = int(input())
c = collections.Counter(prime_factorize(n))
ans = 0
for p_num in c.values():
    i = 0
    tmp = 0
    while True:
        i += 1
        tmp += i
        if p_num < tmp:
            break
    ans += i - 1
print (ans)
