import sys
import math 
ni = lambda: int(ns())
na = lambda: list(map(int, input().split()))
ns = lambda: input()
N = ni()
A = na()
minas=0
tmp=10**9
for i in range(N):
    tmp = min(tmp,abs(A[i]))
    if(A[i]<0):
        minas +=1
        A[i]=-A[i]

#負の数が奇数個
if(minas%2==1):
    #print(tmp)
    print(sum(A)-2*tmp)
else:
    print(sum(A))
