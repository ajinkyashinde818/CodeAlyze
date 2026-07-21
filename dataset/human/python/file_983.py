import sys
import math
from pprint import pprint

def solve(n, s):

    ans = 0
    if s[0] == "W" or s[2*n-1] == "W":
        return ans

    l_c = 0
    r_c = 0
    o_c = 1
    mod = 10**9 + 7
    for s_i in s:
        if s_i == "B" and (l_c - r_c) % 2 == 0:
            l_c += 1
        elif s_i == "W" and (l_c - r_c) % 2 == 0:
            o_c *= l_c - r_c
            o_c %= mod
            r_c += 1
        elif s_i == "B" and (l_c - r_c) % 2 == 1:
            o_c *= l_c - r_c
            o_c %= mod
            r_c += 1
        elif s_i == "W" and (l_c - r_c) % 2 == 1:
            l_c += 1
        # print(s_i, l_c, r_c, o_c)
        if l_c - r_c < 0:
            return 0
    # print(l_c, r_c, o_c)
    if l_c - r_c > 0:
        return 0

    return (o_c * math.factorial(n)) % mod

if __name__ == '__main__':
    n = int(sys.stdin.readline().strip())
    s = list(sys.stdin.readline().strip())
    print(solve(n, s))
