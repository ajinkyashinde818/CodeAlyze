def examA():
    X,Y = LS()
    if ord(X)==ord(Y):
        ans = "="
    elif  ord(X)>ord(Y):
        ans = ">"
    else:
        ans = "<"
    print(ans)


import sys,copy,bisect,itertools
from heapq import heappop,heappush,heapify
from collections import Counter,defaultdict,deque
def I(): return int(sys.stdin.readline())
def LI(): return list(map(int,sys.stdin.readline().split()))
def LS(): return sys.stdin.readline().split()
def S(): return sys.stdin.readline().strip()
mod = 10**9 + 7
inf = float('inf')

examA()
