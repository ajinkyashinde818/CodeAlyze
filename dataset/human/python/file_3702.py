import collections
import math


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


def count_num(n):
    i = 2
    ret = 1
    while True:
        n = n - i
        if n <= 0:
            return ret
        i = i+1
        ret = ret + 1


def main():
    N = int(input())
    list_factorize = prime_factorize(N)
    c = collections.Counter(list_factorize)
    list_key = list(c.keys())
    list_count = list(c.values())
    ans = 0
    for i in range(0, len(list_key)):
        num = list_count[i]
        ans += count_num(num)
    print(ans)


if __name__ == '__main__':
    main()
