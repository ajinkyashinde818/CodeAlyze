import itertools
import sys
import math
import numpy as np
import fractions
from collections import deque
from itertools import combinations
from functools import reduce
from functools import lru_cache
from bisect import insort
sys.setrecursionlimit(10**9)

def main():
    N = int(input())

    ans = 0
    if N % 2 == 0:
        max = math.ceil(math.log(10**18/2,5))
        for i in range(1,max):
            ans += N // (pow(5,i) * 2)

    print(ans)


if __name__ == "__main__":
  main()
