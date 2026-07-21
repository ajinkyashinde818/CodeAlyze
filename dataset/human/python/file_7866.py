import math,sys
from collections import Counter, defaultdict, deque
from sys import stdin, stdout
input = stdin.readline
lili=lambda:list(map(int,sys.stdin.readlines()))
li = lambda:list(map(int,input().split()))
#for deque append(),pop(),appendleft(),popleft(),count()
I=lambda:int(input())
S=lambda:input().strip()
mod = 1000000007

n,k,s=li()
c=0
f=0
while(k>0 and n>0):
    print(s,end=" ")
    k-=1
    n-=1
while(n):
    if(s==0):
        print(1,end=" ")
    elif(s==(10**9)):
        print(s-1,end=" ")
    else:
        print(s+1,end=" ")
    n-=1


print("")
