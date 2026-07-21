from math import ceil
from numba import njit

@njit(cache=True)
def solve(rm,gm,bm,R,G,B,n):
    ans = 0
    for r in range(rm+1):
        for g in range(gm+1):
            x = n-(r*R+g*G)
            if x >= 0:
                ans += (x%B == 0)
    return ans
R, G, B, n = map(int, input().split())
rm = ceil(n / R)
gm = ceil(n / G)
bm = ceil(n / B)

print(solve(rm,gm,bm,R,G,B,n))
