import sys
sys.setrecursionlimit(10**6)
from math import floor,ceil,sqrt,factorial,log,sin,cos
from heapq import heappop, heappush, heappushpop
from collections import Counter,defaultdict,deque
from itertools import accumulate,permutations,combinations,product,combinations_with_replacement
from bisect import bisect_left,bisect_right
from copy import deepcopy
from operator import itemgetter
from fractions import gcd
mod = 10 ** 9 + 7
inf = float('inf')
ninf = -float('inf')
 
#整数input
def ii(): return int(sys.stdin.readline().rstrip()) #int(input())
def mii(): return map(int,sys.stdin.readline().rstrip().split())
def limii(): return list(mii()) #list(map(int,input().split()))
def lin(n:int): return [ii() for _ in range(n)]
def llint(n: int): return [limii() for _ in range(n)]
#文字列input
def ss(): return sys.stdin.readline().rstrip() #input()
def mss(): return sys.stdin.readline().rstrip().split()
def limss(): return list(mss()) #list(input().split())
def lst(n:int): return [ss() for _ in range(n)]
def llstr(n: int): return [limss() for _ in range(n)]

#本当に貪欲法か？ DP法では？？
#本当に貪欲法か？ DP法では？？
#本当に貪欲法か？ DP法では？？

s=list(ss())

cntx=0

chk=True
i=0
j=len(s)-1



while chk:
    if s[i]==s[j]:
        i+=1
        j-=1
    
    elif s[i]!=s[j] and s[i]!="x" and s[j]!="x":
        print(-1)
        exit()
    
    elif s[i]!=s[j] and s[i]=="x" and s[j]!="x":
        cntx+=1
        i+=1
    
    elif s[i]!=s[j] and s[i]!="x" and s[j]=="x":
        cntx+=1
        j-=1
    
    #print(i,s[i],j,s[j])
    
    if i>=j:
        print(cntx)
        exit()
