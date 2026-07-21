from sys import stdin
import sys
import math
from functools import reduce
import functools
import itertools
from collections import deque

s = deque(stdin.readline().rstrip())
n = int(stdin.readline().rstrip())

flag = 0

for i in range(n):
    q = [x for x in stdin.readline().rstrip().split()]

    if len(q) == 1:
        flag = 1 - flag
    else:
        if (q[1] == "1" and flag == 0) or (q[1] == "2" and flag == 1):
            s.appendleft(q[2])
        else:
            s.append(q[2])

if flag == 1:
    s = ''.join(s)[::-1]
else:
    s = ''.join(s)
print (s)
