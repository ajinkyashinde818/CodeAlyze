import sys
import math
from collections import defaultdict

sys.setrecursionlimit(10**7)
def input():
    return sys.stdin.readline()[:-1]

mod = 10**9 + 7

def I(): return int(input())
def II(): return map(int, input().split())
def III(): return list(map(int, input().split()))
def Line(N,num):
    if N<=0:
        return [[] for _ in range(num)]
    elif num==1:
        return [I() for _ in range(N)]
    else:
        read_all = [tuple(II()) for _ in range(N)]
        return map(list, zip(*read_all))

#################

N,K,S = II()

if S==1:
    A = [1]*K + [2]*(N-K)
elif S==10**9:
    if K==0:
        A = [1]*N
    else:
        A = [10**9]*K + [1]*(N-K)
else:
    A = [S]*K + [10**9]*(N-K)

print(*A)
