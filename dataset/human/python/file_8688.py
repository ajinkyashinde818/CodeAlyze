import sys
import math
from collections import defaultdict
k,n=map(int,sys.stdin.readline().split())
arr=list(map(int,sys.stdin.readline().split()))
dis=-1
for i in range(n-1):
    d=arr[i+1]-arr[i]
    dis=max(dis,d)
d=(k-arr[-1]+arr[0])
dis=max(dis,d)
print(k-dis)
