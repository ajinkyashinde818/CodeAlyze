import sys
import math 
from collections import defaultdict
input = lambda : sys.stdin.readline().strip()
n = int(input())
factors = defaultdict(int)
while n%2==0:
    factors[2]+=1
    n = n//2
for i in range(3,int(n**0.5)+1,2):
    while n%i==0:
        factors[i]+=1
        n = n//i 
if n>2:
    factors[n]+=1
ans = 0
for k in factors:
    ans += (-1+int((1+8*(factors[k]))**0.5))//2
print(ans)
