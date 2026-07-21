import bisect,collections,copy,heapq,itertools,math,numpy,string
import sys
from bisect import bisect_left, bisect_right, insort
def S(): return sys.stdin.readline().rstrip()
def I(): return int(sys.stdin.readline().rstrip())
def MI(): return map(int,sys.stdin.readline().rstrip().split())
def MS(): return map(str,sys.stdin.readline().rstrip().split())
def LI(): return list(map(int,sys.stdin.readline().rstrip().split()))
def LS(): return list(sys.stdin.readline().rstrip().split())
#N = I()
#A = [LI() for _ in range(N)]

n,k = MI()
a = LI()
ans = [1] * n
memo = [-1] * n
memo[0] = 0
s = 0
for i in range(1,n):
    if memo[a[ans[i-1]-1]-1] == -1:
        ans[i] = a[ans[i-1]-1]
        s += 1
        memo[ans[i] - 1] = s

    else:
        t = memo[a[ans[i-1]-1]-1]
        break
if k <= t:
    print(ans[k])
elif t == 0:
    print(ans[(k - 1) % (s-t +1) +1])
else:
    print(ans[(k-(t-1)-1) % (s-t+1) + t])
