from collections import Counter,defaultdict
import sys,heapq,bisect,math,itertools,string,queue
mod = 10**9+7
def inp(): return int(sys.stdin.readline())
def inpl(): return list(map(int, sys.stdin.readline().split()))
def inpl_str(): return list(sys.stdin.readline().split())
def conb(n,r): return math.factorial(n) // (math.factorial(n - r) * math.factorial(r))


n = inp()
a = inpl()
b = inpl()
c = inpl()
res = 0
for i in range(n):
    res += b[a[i]-1]
    if i > 0 and a[i] == a[i-1] + 1:
        res += c[a[i-1]-1]
print(res)
