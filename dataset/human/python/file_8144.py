import math
import string
import itertools
import fractions
import heapq
import collections
import re
import array
import bisect
import sys
import random
import time
inf = 10**9


def main():
    k, s = map(int, input().split())

    c = 0
    for i in range(k+1):
        if i > s:
            break
        for j in range(k+1):
            if i + j > s:
                break
            if s-i-j <= k:
                c += 1

    print(c)


if __name__ == '__main__':
    main()
