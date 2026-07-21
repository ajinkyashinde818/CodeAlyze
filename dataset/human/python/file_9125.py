import numpy as np
import functools
import math
import scipy
import fractions
import itertools

def solve():
    s = input()
    s = s[::-1]
    hoge = ["maerd","remaerd","esare","resare"]
    i, bit = 0, 0
    while True:
        if i == len(s):
            break
        if s[i:i+5] == hoge[0]:
            i += 5
        elif s[i:i+7] == hoge[1]:
            i += 7
        elif s[i:i+5] == hoge[2]:
            i += 5
        elif s[i:i+6] == hoge[3]:
            i += 6
        else:
            print("NO")
            bit = 1
            break
    if bit == 0:
        print("YES")
    return 0

if __name__ == "__main__":
    solve()
