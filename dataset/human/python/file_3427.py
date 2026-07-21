import sys

input = lambda: sys.stdin.readline().rstrip()


def factorize(n):
    b = 2
    fct = dict()
    while b * b <= n:
        while n % b == 0:
            n //= b
            if b in fct:
                fct[b] += 1
            else:
                fct[b] = 1
        b = b + 1
    if n > 1:
        if n in fct:
            fct[n] += 1
        else:
            fct[n] = 1
    return fct


def solve():
    N = int(input())
    prime_list = factorize(N)

    if N == 1:
        print(0)
        exit()

    ans = 0
    for p, num in prime_list.items():
        i = 1
        m = 1
        while True:
            if num >= m:
                ans += 1
            else:
                break
            i += 1
            m += i

    print(ans)


if __name__ == '__main__':
    solve()
