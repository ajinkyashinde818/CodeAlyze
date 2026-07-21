import math
import numpy as np
import sys
input = sys.stdin.readline
def IL(): return list(map(int,input().split()))
def SL(): return input().split()
def I(): return int(sys.stdin.readline())
def S(): return input()

X,Y = SL()
l = ["A","B","C","D","E","F"]

if l.index(X) < l.index(Y):
    print("<")
elif l.index(X) == l.index(Y):
    print("=")
else:
	print(">")
