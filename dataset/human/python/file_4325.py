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
    import collections
    p = collections.Counter(prime_factorize(N))
    l = list(p.values())
    ans = 0
    for i in range(len(l)):
        c = l[i]
        if(c == 1 or c == 2):
            ans += 1
            continue
        for j in range(c):
            if ((j * (j + 1)) // 2 == c):
                ans += j
                break
            elif ((j * (j + 1)) // 2 > c):
                ans += j - 1
                break
    print(ans)


if __name__ == "__main__":
    main()
