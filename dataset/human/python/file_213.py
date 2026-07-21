import sys
stdin = sys.stdin
 
sys.setrecursionlimit(10**5) 
 
def li(): return map(int, stdin.readline().split())
def li_(): return map(lambda x: int(x)-1, stdin.readline().split())
def lf(): return map(float, stdin.readline().split())
def ls(): return stdin.readline().split()
def ns(): return stdin.readline().rstrip()
def lc(): return list(ns())
def ni(): return int(stdin.readline())
def nf(): return float(stdin.readline())

from bisect import bisect_left
from itertools import combinations

n = ni()

cands = []
for i in range(1,10**5):
    cand = (i+1)*i // 2
    if cand > 10**5:
        break
    cands.append((i+1)*i // 2)
    
if not n in cands:
    print('No')

else:
    setnum = bisect_left(cands, n) + 2
    sets = list(combinations([i for i in range(1,setnum+1)], 2))
    grid = [[] for _ in range(setnum)]
    for i, (set1, set2) in enumerate(sets):
        grid[set1-1].append(i+1)
        grid[set2-1].append(i+1)
    
    print('Yes')
    print(setnum)
    for row in grid:
        print(len(row), *row)
