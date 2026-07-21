from collections import Counter
import sys

sys.setrecursionlimit(10 ** 6)

mod = 1000000007
inf = int(1e18)

dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]


def inverse(a):
    return pow(a, mod - 2, mod)


def usearch(x, a):
    lft = 0
    rgt = len(a) + 1
    while rgt - lft > 1:
        mid = (rgt + lft) // 2
        if a[mid] <= x:
            lft = mid
        else:
            rgt = mid
    return lft


def main():
    n=int(input())
    i = 2
    m = {}
    while i*i <= n:
        while n % i == 0:
            m[i] = m.get(i, 0) + 1
            n //= i
        i += 1
    if n != 1:
        m[n] = m.get(i, 0) + 1
    s = 0
    for v in m.values():
        i = 1
        while i <= v:
            s += 1
            v -= i
            i += 1
    print(s)

main()
