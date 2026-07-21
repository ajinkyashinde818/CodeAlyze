from bisect import bisect_right, bisect_left
from itertools import groupby, permutations, combinations
from fractions import gcd
import numpy as np
from sys import stdin, stderr


def lcm(x, y):
    return (x * y) // gcd(x, y)


def main():
    N, K, S = [int(x) for x in input().split()]
    if S < 10**9:
        return ([S] * K) + ([S+1] * (N-K))
    else:
        return ([S] * K) + ([1] * (N-K))


if __name__ == "__main__":
    print(" ".join([str(x) for x in main()]))
