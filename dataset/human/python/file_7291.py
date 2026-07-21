from copy import deepcopy
from sys import exit,setrecursionlimit
import math
from collections import defaultdict,Counter,deque
from fractions import Fraction as frac
import fractions
from functools import reduce
from operator import mul
import bisect
import sys
import logging
import heapq
import itertools

logging.basicConfig(level=logging.ERROR)

#input = sys.stdin.readline

setrecursionlimit(1000000)


def main():
    s =  input()
    querry = int(input())
    f = []
    l = []
    r = 0
    for _ in range(querry):
        q = input().split(' ')
        if(q[0] == '1'):
            r += 1
        else:
            if((int(q[1]) + r) % 2 == 0):
                l.append(q[2])
            else:
                f.append(q[2])
    for i in f[::-1] if r%2 == 0 else l[::-1]:
        print(i,end = '')
    print(s if r%2==0  else s[::-1],end = '')
    for i  in l if(r%2==0) else f:
        print(i,end='')
    print()

main()
