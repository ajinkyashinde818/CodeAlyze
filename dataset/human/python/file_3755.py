from collections import Counter

def main():
    N = int(input())
    pf = prime_factorize(N)

    ans = 0
    for v in pf.values():
        for i in range(1, 100000000):
            if i > v:
                break
            ans += 1
            v -= i

    print(ans)


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
    return Counter(a)

main()
