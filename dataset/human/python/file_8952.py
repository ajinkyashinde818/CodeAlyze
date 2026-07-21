from collections import Counter,defaultdict,deque
from heapq import heappop,heappush,heapify
from bisect import bisect_left,bisect_right 
import sys,math,itertools,fractions,pprint
sys.setrecursionlimit(10**8)
mod = 10**9+7
INF = float('inf')
def inp(): return int(sys.stdin.readline())
def inpl(): return list(map(int, sys.stdin.readline().split()))

s = input()[::-1]
n = len(s)
d = [['maerd',5],['remaerd',7],['esare',5],['resare',6]]
ind = 0
while True:
    if ind == n:
        print('YES')
        break
    ok = False
    for t,a in d:
        if ind + a <= n and s[ind:ind+a] == t:
            # print(s[ind:ind+a],t)
            ind += a
            ok = True
            break
    if not ok:
        print('NO')
        break
