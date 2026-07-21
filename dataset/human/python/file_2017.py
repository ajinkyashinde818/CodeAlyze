import sys
from collections import Counter

sys.setrecursionlimit(10 ** 7)
f_inf = float('inf')
mod = 10 ** 9 + 7


def resolve():
    n = int(input())
    s = input()

    res = 1
    D = Counter(s)
    for v in D.values():
        res *= (v + 1)
        res %= mod
    print(res - 1)


if __name__ == '__main__':
    resolve()
