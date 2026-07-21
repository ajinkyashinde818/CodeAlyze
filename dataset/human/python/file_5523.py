from sys import stdin
import math
import bisect
import heapq
import numpy as np

inf = 10**10
li = []
s = stdin.readline().rstrip()
for i in s:
    li.append(i)

li = li[:1]+li[2:]

if li[0]==li[1]:
    print("=")
else:
    lin = sorted(li)
    if li == lin:
        print("<")
    else:
        print(">")
