from collections import defaultdict
n,k=map(int, input().split())
A=[int(i)-1 for i in input().split()]
now=0
loop=[]
dd = defaultdict(int)
if k>=n:
    while k!=0:
        k-=1
        now = A[now]
        if dd[now]>0:
            break
        else:
            dd[now]+=1
        if k==0:
            print(now)
            exit()
        loop.append(now)
    loop = loop[loop.index(now):]
    loop.append(now)
    t = len(loop)-1
    a=(k%t)
    while a>0:
        a-=1
        now = A[now]
    print(now+1)
else:
    while k!=0:
        k-=1
        now = A[now]
    print(now+1)
