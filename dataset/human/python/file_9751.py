import sys
sys.setrecursionlimit(10**6)
n,k=map(int,input().split())
a=list(map(int,input().split()))
seen=[False]*n
l=[1]
now=1
while 1:
    now=a[l[-1]-1]
    l.append(now)
    if seen[now-1]:
        break
    seen[now-1]=True
now=l[-1]
until=l.index(now)
if until>k:
    print(l[k])
    sys.exit()
k-=until
loop=len(l[until:-1])
#print(l)
k%=loop
print(l[until+k])
#print(l)
#print(until,now)
