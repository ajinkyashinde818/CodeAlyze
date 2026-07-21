import math
from math import gcd
INF = float("inf")

import sys
input=sys.stdin.readline
sys.setrecursionlimit(500*500)
import itertools
from collections import Counter,deque

def main():
    n,k = map(int, input().split())
    a = list(map(int, input().split()))

    c = []
    mark = [-1]*n
    pos,l = 0,0
    while 1:
        if mark[pos] >= 0:
            l = mark[pos]
            break
        mark[pos] = len(c)
        c.append(pos)
        pos = a[pos] - 1
    if k <= l:
        print(c[k] + 1)
    else:
        k -= l
        print(c[l + k%(len(c) - l)] + 1)
if __name__=="__main__":
    main()
