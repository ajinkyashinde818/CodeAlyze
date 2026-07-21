from collections import Counter,defaultdict,deque
from heapq import heappop, heappush
import sys,bisect,math,itertools,string,queue
sys.setrecursionlimit(10**8)
mod = 10**9+7
def inp(): return int(sys.stdin.readline())
def inpl(): return list(map(int, sys.stdin.readline().split()))
def inpl_str(): return list(sys.stdin.readline().split())
def inpln(n): return list(int(sys.stdin.readline()) for i in range(n))

d,g = inpl()
p = [0] * d
c = [0] * d
for i in range(d):
    p[i], c[i] = inpl()
res = float('inf')

for flag in itertools.product((0,1),repeat=d):
    sco = 0
    cnt = 0
    for i,j in enumerate(flag):
        if j:
            sco += (i+1)*100*p[i] + c[i]
            cnt += p[i]
    # print(flag,sco,cnt)
    if sco >= g:
        res = min(res, cnt)
    else:
        rem = g - sco #残り
        for i,j in enumerate(flag):
            if not j:
                tmp = -(-rem//((i+1)*100))
                # print(flag,tmp)
                if tmp < p[i]:
                    res = min(res, cnt+tmp)
print(res)
