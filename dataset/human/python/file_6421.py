import numpy as np
import functools
import math
import scipy
import fractions
import itertools

def solve():
    n = int(input())
    if n % 2 != 0:
        print(0)
    else:
        i = 5
        ans = 0
        while i <= n:
            ans += n // (i*2)
            i *= 5
        print(ans)
    return 0

if __name__ == "__main__":
    solve()
