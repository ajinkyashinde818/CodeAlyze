import sys
sys.setrecursionlimit(1000000000)
import math
from fractions import gcd
def lcm(a, b): return a * b // gcd(a, b)
from itertools import count, permutations
from functools import lru_cache
from collections import deque, defaultdict
from pprint import pprint
ii = lambda: int(input())
mis = lambda: map(int, input().split())
lmis = lambda: list(mis())
INF = float('inf')
N1097 = 10**9 + 7

def meg(f, ok, ng):
    while abs(ok-ng)>1:
        mid = (ok+ng)//2
        if f(mid):
            ok=mid
        else:
            ng=mid
    return ok

def get_inv(n, modp):
    return pow(n, modp-2, modp)

def factorials_list(n, modp):    # 10**6
    fs = [1]
    for i in range(1, n+1):
        fs.append(fs[-1] * i % modp)
    return fs

def invs_list(n, fs, modp):     # 10**6
    invs = [get_inv(fs[-1], modp)]
    for i in range(n, 1-1, -1):
        invs.append(invs[-1] * i % modp)
    invs.reverse()
    return invs

def comb(n, k, modp):
    vn = vk = vn_k = 1
    for i in range(1, n+1):
        vn = vn * i % modp
        if i == k:
            vk = vn
        if i == n-k:
            vn_k = vn
    return vn * get_inv(vk, modp) * get_inv(vn_k, modp) % modp

def comb_from_list(n, k, modp, fs, invs):   
    return fs[n] * invs[n-k] * invs[k] % modp

#

def main():
    N,R=mis()
    if N>=10:
        print(R)
    else:
        print(R+100*(10-N))

main()
