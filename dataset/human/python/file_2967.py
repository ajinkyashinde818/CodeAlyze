import numpy as np
import sys
sys.setrecursionlimit(10**6)

n=int(input())

m=int(np.sqrt(n))+1

if n==1 or n==0:
    print(0)
    exit()

ans=0
for i in range(2,m):
    cnt=0
    for j in range(44):
        if n%i==0:
            n=n/i
#            print("i=",i,"n=",n)
            cnt+=1
        else:
            break
    if 1<=cnt<3:
        ans+=1
    if 3<=cnt<6:
        ans+=2
    if 6<=cnt<10:
        ans+=3
    if 10<=cnt<15:
        ans+=4
    if 15<=cnt<21:
        ans+=5
    if 21<=cnt<28:
        ans+=6
    if 28<=cnt<36:
        ans+=7
    if 36<=cnt<45:
        ans+=8

if int(n)!=1:
    ans+=1

if ans==0:
    print(1)
    exit()

print(ans)
