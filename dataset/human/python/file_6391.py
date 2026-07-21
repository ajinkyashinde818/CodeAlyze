import sys

sys.setrecursionlimit(10 ** 7)
f_inf = float('inf')
mod = 10 ** 9 + 7


def resolve():
    n = int(input())
    if n % 2:
        print(0)
        exit()
    n //= 2
    res = 0
    while n:
        res += n // 5
        n //= 5
    print(res)


if __name__ == '__main__':
    resolve()
