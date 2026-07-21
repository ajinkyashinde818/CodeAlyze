import math
import collections
import fractions
import itertools

def solve():
    k,s = map(int, input().split())
    ans = 0
    for x in range(k+1):
        for y in range(k+1):
            z = s - x - y
            if 0 <= z <= k:
                ans += 1
    print(ans)
    return 0

if __name__ == "__main__":
    solve()
