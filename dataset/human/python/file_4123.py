import sys
import  math
from heapq import *
import fractions
from collections import defaultdict
stdin = sys.stdin
     
ns = lambda: stdin.readline().rstrip()
ni = lambda: int(stdin.readline().rstrip())
nm = lambda: map(int, stdin.readline().split())
nl = lambda: list(map(int, stdin.readline().split()))


def factorization(n):
    arr = []
    temp = n
    for i in range(2, int(-(-n**0.5//1))+1):
        if temp%i==0:
            cnt=0
            while temp%i==0:
                cnt+=1
                temp //= i
            arr.append([i, cnt])

    if temp!=1:
        arr.append([temp, 1])

    if arr==[]:
        arr.append([n, 1])

    return arr


N=int(input())
mod_l=factorization(N)
ans=0

if(N==1):
    print(0)
    sys.exit(0)
    
for i in mod_l:
    tmp=i[1]
    c=1
    while(c<=tmp):
        tmp-=c
        c+=1
        ans+=1

print(ans)
