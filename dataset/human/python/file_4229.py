N = int(input())

def make_divisors(n):
    divisors = []
    for i in range(1, int(n**0.5)+1):
        if n % i == 0:
            divisors.append(i)
            if i != n // i:
                divisors.append(n//i)

    divisors.sort()
    return divisors

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

ans = 0
alr = set()
while True:
    divisors = set(make_divisors(N))
    diff = divisors.difference(alr)
    pos = list(diff)
    pos.sort()
    for num in pos:
        fact = prime_factorize(num)
        if len(set(fact)) == 1:
            alr.add(num)
            ans += 1
            N = N // num
            break
    else:
        break

print(ans)
