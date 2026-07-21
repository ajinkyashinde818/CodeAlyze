import sys
input = sys.stdin.readline
sys.setrecursionlimit(10 ** 7)
import bisect
import numpy as np
import math
from collections import deque
from collections import defaultdict
from math import gcd

"""nを素因数分解"""
"""2以上の整数n => [[素因数, 指数], ...]の2次元リスト"""

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

N = int(input())

if N == 1:
    print(0)
else:
    fact = factorization(N)

    ans = 0
    for p, r in fact:
        index = 0
        cum_sum = 1
        cnt = 1
        while cum_sum <= r:
            index += 1
            cum_sum += cnt + 1
            cnt += 1

        ans += index
    print(ans)
