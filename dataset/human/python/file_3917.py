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

def main():
    N = int(input())
    P = prime_factorize(N)
    C = collections.Counter(P)
    # print(C)

    ans = 0
    for k, v in C.items():
        x = 1
        while v - x >= 0:
            v -= x
            x += 1
            ans += 1

    print(ans)


if __name__ == '__main__':
    main()
