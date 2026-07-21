import collections
import itertools
import functools
import math
import scipy.special

if __name__ == "__main__":
    k, s = map(int, input().split())
    res = 0
    mi = min(k, s)
    ma = max(k, s)
    for i in range(mi + 1):
        for j in range(mi + 1):
            if 0 <= s - i - j and s - i - j <= k:
                res += 1
    print(res)
