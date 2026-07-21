from bisect import bisect_right, bisect_left
from itertools import groupby, permutations, combinations
from fractions import gcd
import numpy as np
from sys import stdin, stderr


def lcm(x, y):
    return (x * y) // gcd(x, y)


def main():
    N = int(input())
    if N % 2 == 1:
        return 0
    d = 10
    m = 1
    ret = 0
    while d <= N:
        ret += m * (N // d)
        d *= 5
    return ret


if __name__ == "__main__":
    print(main())
