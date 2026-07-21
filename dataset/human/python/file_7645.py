import bisect,copy,heapq,string
from collections import *
from math import *
from itertools import *
import sys
def input() : return sys.stdin.readline().strip()
def INT()   : return int(input())
def MAP()   : return map(int,input().split())
def LIST()  : return list(MAP())

s = input()
q = INT()
p = [0]*q
flag = 0
c0 = c1 = ''

for i in range(q):
        p[i] = input()
        if p[i][0] == '1':
                flag = 1 - flag
        else:
                t, f, c = p[i].split()
                if (f == '1' and flag == 0) or (f == '2' and flag == 1):
                        c0 = c + c0
                else:
                        c1 = c1 + c

s = c0 + s + c1
print(s if flag == 0 else s[::-1])
