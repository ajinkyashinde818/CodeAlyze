import collections

def prime_factorize(n):
    """素因数分解
    """
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

def resolve():
    N = int(input())
    factor_list = prime_factorize(N)
    if len(factor_list) == 0:
        print(0)
        return
    factor_count = collections.Counter(factor_list)
    div_count = 0
    for factor, count in factor_count.items():
        e = 1
        while True:
            if count >= e:
                N = N // (factor**e)
                div_count += 1
                count -= e
                e += 1
            else:
                break
    print(div_count)

resolve()
