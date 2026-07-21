from math import floor
import sys
from copy import copy

from collections import deque
input = sys.stdin.readline
'''
n, m = map(int, input().split())
n = int(input())
A = list(map(int, input().split()))
S = input().strip()
for test in range(int(input())):
'''
inf = 100000000000000000  # 1e17
mod = 998244353




S = input().strip()
D = deque(S)


n = int(input())
reverse = False
for operation in range(n):
    data = input().strip()
    if data[0] == "1":
        if reverse is False:
            reverse = True
        else:
            reverse = False
    else:
        f = data[2]
        ele = data[4]
        if (f == "1" and reverse is False) or (f == "2" and reverse == True):
            D.appendleft(ele)
        else:
            D.append(ele)
#    print(S)
# print(reverse)
if reverse is True:
    D.reverse()
for d in D:
    print(d,end="")
