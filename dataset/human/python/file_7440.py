import math
import string
import itertools
import fractions
import heapq
import collections
import re
import array
import bisect
import sys
import random
import time
from collections import deque
inf = 10**9


def main():
    o = 1
    s = deque(input())
    q = int(input())
    for i in range(q):
        qu = input().split()
        if qu[0] == '1':
            o = int(not o)
        else:
            addo = 1 if qu[1] == '1' else 0
            if o == addo:
                s.appendleft(qu[2])
            else:
                s.append(qu[2])
        # print(s, o)
    
    if o:
        print(''.join(s))
    else:
        s.reverse()
        print(''.join(s))




if __name__ == '__main__':
    main()
