import itertools
import sys
import math
import numpy as np
from collections import deque
from itertools import combinations
from functools import reduce
from functools import lru_cache
sys.setrecursionlimit(10**9)


def main():
    N,R = map(int,input().split())
    if N >= 10:
        print(R)
    else:
        print(R+(10-N)*100)



if __name__ == "__main__":
  main()
