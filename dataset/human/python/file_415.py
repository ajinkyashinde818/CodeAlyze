import numpy as np
import functools
import math
import scipy
import fractions
import itertools

def solve():
    n = int(input())
    a = list(map(int, input().split()))
    hoge = 0
    ans = 0
    for i in range(n):
        if a[i] < 0:
            hoge += 1
    if 0 in a or hoge % 2 == 0:
        for i in range(n):
            ans += abs(a[i])
    else:
        huga = []
        for i in range(n):
            a[i] = abs(a[i])
            ans += abs(a[i])
            if a[i] > 0:
                huga.append(a[i])
        ans -= min(huga)*2
    print(ans)
    return 0

if __name__ == "__main__":
    solve()
