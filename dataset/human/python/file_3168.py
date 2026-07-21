def factorize(n):
    fact = dict()
    k = n
    for i in range(2, int(-(-n ** 0.5 // 1)) + 1):
        if k % i == 0:
            c = 0
            while k % i == 0:
                c += 1
                k //= i
            fact[i] = c
    if k != 1:
        fact[k] = 1
    if not fact:
        fact[n] = 1
    return fact


def main():
    n = int(input())
    if n == 1:
        print(0)
        return
    c = sum([[i for _ in range(i + 1)] for i in range(9)], [])
    print(sum(c[f] for f in factorize(n).values()))


if __name__ == '__main__':
    main()
