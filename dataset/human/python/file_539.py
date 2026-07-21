import sys
from functools import lru_cache
sys.setrecursionlimit(10**7)
INF = 10 ** 18

def LI(): return [int(x) for x in sys.stdin.readline().split()]
def II(): return int(sys.stdin.readline())

N = II()
A_li = LI()
N = len(A_li)

@lru_cache(maxsize=None)
def dp(i,j):
    if i == 0:
        if j == 0: return A_li[0]
        elif j == 1: return -A_li[0]
    else:
        if j == 0: return max(dp(i-1, 0) + A_li[i], dp(i-1, 1) - A_li[i])
        elif j == 1: return max(dp(i-1, 0) - A_li[i], dp(i-1, 1) + A_li[i])

print(dp(N-1,0))
