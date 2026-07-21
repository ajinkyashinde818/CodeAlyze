from collections import defaultdict,deque
import sys,heapq,bisect,math,itertools,string,queue,datetime
sys.setrecursionlimit(10**8)
INF = float('inf')
mod = 10**9+7
eps = 10**-7
def inpl(): return list(map(int, input().split()))
def inpl_s(): return list(input().split())

S = input()
S1 = S2 = S

S1 = S1.replace('dreamer','')
S1 = S1.replace('dream','')
S1 = S1.replace('eraser','')
S1 = S1.replace('erase','')

S2 = S2.replace('eraser','')
S2 = S2.replace('erase','')
S2 = S2.replace('dreamer','')
S2 = S2.replace('dream','')

if S1 == '' or S2 == '':
	print('YES')
else:
	print('NO')
