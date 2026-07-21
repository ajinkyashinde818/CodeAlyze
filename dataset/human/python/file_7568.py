import sys
import math
import copy
import queue
input = sys.stdin.readline
def LI(): return [int(x) for x in input().split()]
INF = 10**15
DD = ((1,0),(0,1),(-1,0),(0,-1))

S = [x for x in input().rstrip()]
n = int(input())

a = [[],[]]
d = 0
for _ in range(n):
    q = list(input().split())
    if q[0] == '1':
        d = 1-d
    else:
        if q[1] == '1':
            a[d].append(q[2])
        else:
            a[1-d].append(q[2])

if d == 1:
    a[1].reverse()
    S.reverse()
    S = ''.join(a[1]) + ''.join(S) + ''.join(a[0])
else:
    a[0].reverse()
    S = ''.join(a[0]) + ''.join(S) + ''.join(a[1])
print (S)
