import sys, math
def input():
    return sys.stdin.readline()[:-1]
from itertools import permutations, combinations
from collections import defaultdict, Counter, deque
from math import factorial
from bisect import bisect_left # bisect_left(list, value)
#from fractions import gcd
enu = enumerate

sys.setrecursionlimit(10**7)
S = input()
Q = int(input())
Que = [input().split() for _ in range(Q)]

d = deque([s for s in S])

oneisleft = True
for q in Que:
    if q[0] == '1':
        oneisleft = not(oneisleft)
    else:
        fi, ci = q[1], q[2]
        if oneisleft:
            if fi == '1':
                d.appendleft(ci)
            else:
                d.append(ci)
        else:
            if fi == '1':
                d.append(ci)
            else:
                d.appendleft(ci)
if oneisleft:
    res = ''.join(list(d))
else:
    res = ''.join(reversed(list(d)))
print(res)
