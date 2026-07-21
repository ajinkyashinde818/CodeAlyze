import math
import itertools
import fractions
import heapq
import collections
import bisect
import sys
import copy

sys.setrecursionlimit(10**9)
mod = 10**7+9
inf = 10**20

s = input()
q = int(input())


sentou = ""
matubi = ""
reverse = False
for i in range(q):
    l = input().split()
    if l[0]=="1":
        reverse = not(reverse)
    else:
        if l[1]=="1":
            if reverse:
                matubi += l[2][::-1]
            else:
                sentou = l[2] + sentou
        else:
            if reverse:
                sentou = l[2][::-1] + sentou
            else:
                matubi += l[2]
    #print(sentou,s,matubi)

if reverse:
    print(matubi[::-1] + s[::-1] + sentou[::-1])
else:
    print(sentou + s + matubi)
