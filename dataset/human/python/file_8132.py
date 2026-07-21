from operator import mul
from functools import reduce
def combinations_count(n, r):
    if n<r: return 0
    r = min(r, n - r)
    numer = reduce(mul, range(n, n - r, -1), 1)
    denom = reduce(mul, range(1, r + 1), 1)
    return numer // denom

def main():
    K,S = map(int, input().split())
    ans = 0
    # x+y<=Sとなるように回す
    for x in range(K+1):
        for y in range(K+1):
            z = S-(x+y)
            if x+y<=S and 0<=z and z<=K: ans += 1
    print(ans)

main()
