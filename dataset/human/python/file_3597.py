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
    cnt = Counter(prime_factorize(N))
    # stock = {k : 1 for k in cnt}
    ans = 0
    for prime in cnt:
        needed = 1
        while cnt[prime] >=needed:         
            ans += 1
            cnt[prime] -= needed
            needed += 1
    print(ans)


if __name__ == "__main__":
    main()
