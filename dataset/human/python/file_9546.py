import math,string,itertools,fractions,heapq,collections,re,array,bisect,sys,random,time,copy,functools
from collections import deque

sys.setrecursionlimit(10**7)
inf = 10**20
mod = 10**9 + 7

DR = [1, -1, 0, 0]
DC = [0, 0, 1, -1]

def LI(): return [int(x) for x in sys.stdin.readline().split()]
def LI_(): return [int(x)-1 for x in sys.stdin.readline().split()]
def LF(): return [float(x) for x in sys.stdin.readline().split()]
def LS(): return sys.stdin.readline().split()
def I(): return int(sys.stdin.readline())
def F(): return float(sys.stdin.readline())
def S(): return input()
     
def main():
    n, k = LI()
    A = LI_()
    visited = set()
    path = []
    cur = 0
    while True:
        visited.add(cur)
        path.append(cur)
        cur = A[cur]
        if cur in visited:
            break
    for i, city in enumerate(path):
        if cur == city:
            loop_st = i
            break
    loop_en = len(path) - 1
    n_loop = loop_en - loop_st + 1
    
    if k > loop_st:
        k -= loop_st
        k %= n_loop
        print(path[loop_st + k] + 1)
    else:
        print(path[k] + 1)

main()
