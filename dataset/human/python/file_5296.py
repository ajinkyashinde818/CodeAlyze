from collections import Counter,defaultdict
import sys,heapq,bisect,math,itertools,string,queue
mod = 10**9+7
def inp(): return int(sys.stdin.readline())
def inpl(): return list(map(int, sys.stdin.readline().split()))
def inpl_str(): return list(sys.stdin.readline().split())
def inpln(n): return list(int(sys.stdin.readline()) for i in range(n))

n,m = inpl()
f = []
t = []
for i in range(m):
    a,b = inpl()
    if a == 1:
        f.append(b)
    elif b == n:
        t.append(a)
t = set(t)
for i in f:
    if i in t:
        print('POSSIBLE')
        break
else:
    print('IMPOSSIBLE')
