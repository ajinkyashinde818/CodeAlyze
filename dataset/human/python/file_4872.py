import sys
import itertools
sys.setrecursionlimit(1000000000)
from heapq import heapify,heappop,heappush,heappushpop
import math
import collections

s = list(input())
t = list(input())
s.sort()
t.sort(reverse=True)
s2 = ""
t2 = ""
for i in range(len(s)):
    s2+=s[i]
for i in range(len(t)):
    t2+=t[i]
dic = [s2,t2]
dic.sort() 
if s2 == t2:
    print("No")
    sys.exit()   
if dic[0] == s2:
    print("Yes")
else:
    print("No")
