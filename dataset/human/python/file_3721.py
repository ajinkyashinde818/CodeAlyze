import bisect
import heapq
import math
import random
import sys
import collections
from decimal import ROUND_CEILING, ROUND_HALF_UP, Decimal
from functools import lru_cache, reduce
from itertools import combinations, combinations_with_replacement, product, permutations
from operator import add, mul, sub, or_

sys.setrecursionlimit(100000)
input = sys.stdin.readline
INF = 2**62-1

def read_int():
    return int(input())

def read_int_n():
    return list(map(int, input().split()))

def read_float():
    return float(input())

def read_float_n():
    return list(map(float, input().split()))

def read_str():
    return input().strip()

def read_str_n():
    return list(map(str, input().split()))

def error_print(*args):
    print(*args, file=sys.stderr)

def factorization(n):
    arr = []
    temp = n
    for i in range(2, int(-(-n**0.5//1))+1):
        if temp%i==0:
            cnt=0
            while temp%i==0:
                cnt+=1
                temp //= i
            arr.append([i, cnt])

    if temp!=1:
        arr.append([temp, 1])

    if arr==[]:
        arr.append([n, 1])

    return arr

def main():
    n = read_int()
    f = factorization(n)
    count = 0
    for x in f:
        if x[0] == 1:
            continue
        lc = x[1]
        for i in range(1,INF):
            if i <= lc:
                lc = lc - i
                count+=1
            else:
                break
    print(count)

if __name__ == '__main__':
    main()
