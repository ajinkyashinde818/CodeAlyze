import itertools
import sys
import math
import numpy as np
from collections import deque
from itertools import combinations
from functools import reduce
from functools import lru_cache
from collections import deque
sys.setrecursionlimit(10**9)

def main():
    S = input()
    Q = int(input())
    d = deque(list(S))
    rev = False

    def insert(x,f):
        g = f == "2" # append
        if rev:
            g = not g

        if g:
            d.append(x)
        else:
            d.appendleft(x)


    for q in range(Q):
        inp = input()
        if inp == "1":
            rev = not rev
        else:
            _,F,C = inp.split()
            insert(C,F)


    if rev:
        d.reverse()

    print("".join(d))



if __name__ == "__main__":
  main()
