from collections import defaultdict,deque
import sys,heapq,bisect,math,itertools,string,queue,datetime,random
sys.setrecursionlimit(10**8)
INF = float('inf')
mod = 10**9+7
eps = 10**-7
def inpl(): return list(map(int, input().split()))
def inpls(): return list(input().split())

N = int(input())
AA = inpl()

cnt = 0
plus_min = INF
mins_max = -INF
ans = 0

for a in AA:
    if a < 0:
        cnt += 1
        mins_max = max(mins_max,a)
        ans -= a
    else:
        plus_min = min(plus_min,a)
        ans += a

if cnt%2 == 0 :
    print(ans)
else:
    ans = max( ans + mins_max*2 , ans - plus_min*2 )
    print(ans)
