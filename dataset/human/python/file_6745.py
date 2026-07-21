from collections import Counter,defaultdict,deque
from bisect import bisect_left
import sys,math,itertools,pprint,fractions,time
sys.setrecursionlimit(10**8)
mod = 10**9+7
INF = float('inf')
def inp(): return int(sys.stdin.readline())
def inpl(): return list(map(int, sys.stdin.readline().split()))

s = input()
n = len(s)
Q = inp()
q = deque()
for i in s:
    q.append(i)
rev = 0
for _ in range(Q):
    tmp = input().split()
    if tmp[0] == '1':
        rev ^= 1
    else:
        if tmp[1] == '1':
            if rev==0: q.appendleft(tmp[2])
            else: q.append(tmp[2])
        else:
            if rev==0: q.append(tmp[2])
            else: q.appendleft(tmp[2])
    # print(_,q)
# print(q)
res = list(q)
if rev: res = res[::-1]
# print(res)
print(''.join(res))
