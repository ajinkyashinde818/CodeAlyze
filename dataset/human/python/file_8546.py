import sys
import itertools
import bisect
from operator import itemgetter
 
MAX_INT = int(10e15)
MIN_INT = -MAX_INT
mod = 1000000007
sys.setrecursionlimit(1000000)
def IL(): return list(map(int,input().split()))
def SL(): return input().split()
def I(): return int(sys.stdin.readline())
def S(): return input()

K,N = IL()
a = IL()

num = K+a[0] - a[-1]
for i in range(N-1):
  num = max(num, a[i+1]-a[i])
print(K-num)
