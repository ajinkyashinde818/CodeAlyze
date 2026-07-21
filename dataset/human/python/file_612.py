import sys
from fractions import gcd

N=input()
A=map(int, sys.stdin.readline().split())

minus_count=0
A_sum=0
A_min=float("inf")
for a in A:
    if a<0:
        minus_count+=1
    a=abs(a)
    A_min=min(A_min,a)
    A_sum+=a

if minus_count%2==0:
    print A_sum
else:
    print A_sum-A_min*2
