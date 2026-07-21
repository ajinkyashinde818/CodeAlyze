n = int(input())
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
if n == 1:
    print(0)
    exit()
primes = prime_factorize(n)
max_primes = primes[-1]
dic = {}
tmp = 0
for i in primes:
    if i not in dic:
        dic[i] = 1
        tmp = 0
        continue
    if tmp == 0:
        tmp = i
    else:
        tmp *= i
        if tmp not in dic:
            dic[tmp] = 1
            tmp = 0
print(len(dic))
