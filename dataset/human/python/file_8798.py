from sys import exit
import math
import collections
ii = lambda : int(input())
mi = lambda : map(int,input().split())
li = lambda : list(map(int,input().split()))

k,n = mi()
a = li()

max_l = 0
for i in range(n-1):
    max_l = max(max_l,a[i+1]-a[i])
max_l = max(max_l,k-a[-1]+a[0])

print(k-max_l)
