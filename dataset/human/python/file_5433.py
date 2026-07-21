def examA():
    N = I()
    if N%10==9:
        ans = "Yes"
    elif N//10==9:
        ans = "Yes"
    else:
        ans = "No"
    print(ans)


import sys
import copy
import bisect
import heapq
from collections import Counter,defaultdict,deque
def I(): return int(sys.stdin.readline())
def LI(): return list(map(int,sys.stdin.readline().split()))
def LS(): return sys.stdin.readline().split()
def S(): return sys.stdin.readline().strip()
mod = 10**9 + 7
inf = float('inf')

examA()
