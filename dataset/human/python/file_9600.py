from math import floor,ceil,sqrt
import fractions
import collections
import itertools
import pprint
from collections import deque
N,K=map(int,input().split())
A=list(map(int,input().split()))
double=[[-1 for _ in range(N)] for _ in range(60)]

for i in range(N):
    double[0][i]=A[i]-1
#pprint.pprint(double)
for i in range(1,60):
    for j in range(N):
        bef=double[i-1][j]
        double[i][j]=double[i-1][bef]
        #pprint.pprint(double[:10])
        #input()
bit=[0]*60

for i in range(60):
    if (K>>i)&1:
        bit[i]=1
#print(double[:5],bit)
piv=0
for i in range(60):
    if bit[i]==1:
        piv=double[i][piv]
print(piv+1)
