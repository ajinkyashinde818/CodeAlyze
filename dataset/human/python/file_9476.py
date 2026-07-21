import math,sys
from sys import stdin, stdout
from collections import Counter, defaultdict, deque
input = stdin.readline
I = lambda:int(input())
li = lambda:list(map(int,input().split()))

def case():
    n,k=li()
    a=li()
    d=defaultdict(int)
    i=0
    d[1]=1
    c=0
    ans=[1]
    while(a[i] not in d):
        d[a[i]]=1
        c+=1 
        ans.append(a[i])
        i=a[i]-1
   # print(i)
    #print(ans)
    if(k<len(ans)):
        print(ans[k%len(ans)])
        return
    for j in range(len(ans)):
        if(ans[j]==a[i]):
            ans=ans[j:]
            k-=j
            break 

    #print(ans,k)
    print(ans[(k)%len(ans)])
    




for _ in range(1):
    case()
