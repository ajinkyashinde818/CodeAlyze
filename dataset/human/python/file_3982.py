import sys
input = sys.stdin.readline

x=int(input())

import math 
L=int(math.sqrt(x))

FACT=dict()

for i in range(2,L+2):
    while x%i==0:
        FACT[i]=FACT.get(i,0)+1
        x=x//i

if x!=1:
    FACT[x]=FACT.get(x,0)+1

ANS=0
for f in FACT.values():
    i=1
    while f:
        if f>=i:
            ANS+=1
            f-=i
            i+=1
        else:
            break
print(ANS)
