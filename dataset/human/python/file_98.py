import sys
import numpy as np
import math  # gcdもあるよ
from collections import deque
from collections import defaultdict
from copy import deepcopy
from itertools import accumulate #リストを与えると累積和を返す
def input(): return sys.stdin.readline().rstrip()
from functools import lru_cache #メモ化

def main():
    RGB = list(map(int,input().split()))
    N = RGB.pop()
    #print(N)
    RGB.sort(reverse=True)
    ans = 0
    for i in range(N//RGB[0]):
        N_1 = N % RGB[0] + RGB[0] * i
        #print(N_1)
        for j in range(N_1//RGB[1]):
            N_2 = N_1 % RGB[1] + RGB[1] * j
            if N_2 % RGB[2] == 0:
                ans += 1
        if N_1 % RGB[2] == 0:
                ans += 1
    for j in range(N//RGB[1]):
            N_1 = N % RGB[1] + RGB[1] * j
            if N_1 % RGB[2] == 0:
                ans += 1
    if N % RGB[2] == 0:
                ans += 1
    print(ans)
    return 0

if __name__ == "__main__":
    main()
