import itertools
import numpy as np
import sys
MAX_INT = int(10e10)
MIN_INT = -MAX_INT
mod = 1000000007
def IL(): return list(map(int,input().split()))
def SL(): return input().split()
def I(): return int(sys.stdin.readline())
def S(): return input()

s = [i for i in S()]
t = [i for i in S()]
f = 0
if len(s)<len(t):
    f = len(s)
s.sort()
t.sort(reverse=True)
for a,b in zip(s,t):
    if a < b:
        print("Yes")
        exit()
    elif a == b:
        f -= 1
if f == 0:
    print("Yes")
else:
    print("No")
