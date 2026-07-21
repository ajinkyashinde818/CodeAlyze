import sys

import collections

sys.setrecursionlimit(10 ** 8)

input = sys.stdin.readline

def prime_factorization(n):
    i = 2
    factors = []
    while i * i <= n:
        if n % i:
            i += 1
        else:
            n //= i
            factors.append(i)
    if n > 1:
        factors.append(n)
    return factors


def main():
    N = int(input())

    x = prime_factorization(N)

    c = collections.Counter(x)

    ans = 0
    for k in c.keys() :
        for i in range(1, 10 ** 5):
            if c[k] >= i:
                c[k] -= i
                ans += 1


    print(ans)



if __name__ == '__main__':
    main()
