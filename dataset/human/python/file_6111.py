import sys
from bisect import *
from collections import *
from copy import deepcopy
from heapq import *
from itertools import *
from math import *
from operator import *
import numpy as np

sys.setrecursionlimit(10**8)

input = sys.stdin.readline

def main():
    """ main """
    N = int(input())
    AS = list(map(int, input().split()))
    BS = list(map(int, input().split()))
    CS = list(map(int, input().split()))

    ans = 0
    prev = -2
    for a in AS:
        plus = BS[a-1]
        if 1 < a and prev == a-1-1:
            plus += CS[a-2]
        ans += plus
        prev = a-1
    print(ans)


if __name__ == '__main__':
    main()
