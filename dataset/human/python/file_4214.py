import sys

sys.setrecursionlimit(10 ** 7)
input = sys.stdin.readline
f_inf = float('inf')
mod = 10 ** 9 + 7


def prime_factorization(n):
    res = []
    for i in range(2, int(pow(n, 0.5)) + 1):
        if n % i == 0:
            ex = 0
            while n % i == 0:
                ex += 1
                n //= i
            res.append(ex)
    if n != 1:
        res.append(1)
    return res


def resolve():
    n = int(input())
    div = prime_factorization(n)

    res = 0
    for ex in div:
        i = 1
        while ex > 0:
            ex -= i
            if ex < 0:
                break
            i += 1
            res += 1
    print(res)


if __name__ == '__main__':
    resolve()
