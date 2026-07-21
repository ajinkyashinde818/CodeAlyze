from collections import Counter
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
def main():
    N = int(input())
    l = prime_factorize(N)
    c = Counter(l)
    r = 0
    ll = [0]
    for i in range(1, 100):
        ll.append(ll[-1] + i)
    for i in c.values():
        for j in range(100):
            if ll[j] > i:
                r += j - 1
                break
    return r

print(main())
