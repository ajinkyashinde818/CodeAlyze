import sys, math
input = sys.stdin.readline
rs = lambda: input().strip()
ri = lambda: int(input())
rl = lambda: list(map(int, input().split()))
mod = 10**9 + 7

A, B = rl()

from fractions import gcd
from functools import reduce

def get_gcd(A):
    return reduce(gcd, A)

def get_lcm(A):
	def lcm_base(a, b):
		return a*b//gcd(a,b)
	return reduce(lcm_base, A, 1)

print(get_lcm([A, B]))
