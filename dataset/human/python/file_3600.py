import sys
import numpy as np
import math
import random
from decimal import Decimal
import itertools
import re
from collections import deque, Counter
from functools import lru_cache

sys.setrecursionlimit(2147483647)
INF = 10**13
def LI(): return list(map(int, sys.stdin.buffer.readline().split()))
def I(): return int(sys.stdin.buffer.readline())
def LS(): return sys.stdin.buffer.readline().rstrip().decode('utf-8').split()
def S(): return sys.stdin.buffer.readline().rstrip().decode('utf-8')
def IR(n): return [I() for i in range(n)]
def LIR(n): return [LI() for i in range(n)]
def SR(n): return [S() for i in range(n)]
def LSR(n): return [LS() for i in range(n)]
def SRL(n): return [list(S()) for i in range(n)]
def MSRL(n): return [[int(j) for j in list(S())] for i in range(n)]
mod = 1000000007

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
	n = I()
	factos = factorization(n)
	count = 0
	for num, facto in factos:
		sum_tmp = 0
		for i in range(1,facto+1):
			sum_tmp += i
			if sum_tmp <= facto:
				count += 1
	if n == 1:
		print(0)
	else:
		print(count)


if __name__ == '__main__':
    main()
