from fractions import gcd
from datetime import date, timedelta
from heapq import*
import math
from collections import defaultdict, Counter, deque
import sys
from bisect import *
import itertools
import copy
sys.setrecursionlimit(10 ** 7)
MOD = 10 ** 9 + 7


def main():
    n, m = map(int, input().split())
    a = [list(input()) for i in range(n)]
    b = [list(input()) for i in range(m)]

    for i in range(n-m+1):
        for j in range(n - m + 1):
            f = True
            for p in range(m):
                for q in range(m):
                    if a[i + p][j + q] != b[p][q]:
                        f= False
            
            if f:
                print("Yes")
                exit()

    print("No")


if __name__ == '__main__':
    main()
