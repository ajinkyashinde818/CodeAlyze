import sys
from math import sqrt
from bisect import bisect_right


def _i(): return int(sys.stdin.readline().strip())


def main():
    n = _i()
    sqn = int(sqrt(n))
    p = [True] * (sqn+1)
    d = {}
    for i in range(2, sqn + 1):
        if not p[i]:
            continue

        for j in range(i+i, sqn+1, i):
            p[j] = False

        while n % i == 0:
            d[i] = d.get(i, 0) + 1
            n //= i

    c = 0 if n == 1 else 1
    arr = [1, 3, 6, 10, 15, 21, 28, 36]
    for v in d.values():
        c += bisect_right(arr, v)
    return c


if __name__ == "__main__":
    print(main())
