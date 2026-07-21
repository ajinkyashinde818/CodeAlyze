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

if __name__ == "__main__":
    N = int(input())
    c = collections.Counter(prime_factorize(N))
    l = list(c.values())
    counter = 0
    for f in l:
        num = 1
        while f >= num:
            f -= num
            num += 1
            counter += 1
    print(counter)
