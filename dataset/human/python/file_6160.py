import itertools
import numpy as np
import sys
input = sys.stdin.readline
def IL(): return list(map(int,input().split()))
def SL(): return input().split()
def I(): return int(sys.stdin.readline())
def S(): return input()

A,B,C = IL()

if A+B < C:
    print(B*2+A+1)
else:
    print(B+C)
