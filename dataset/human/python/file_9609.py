import sys
input=sys.stdin.readline
n,k=map(int,input().split())
a=list(map(int,input().split()))
check=[False]*n
now=0
order=[]
while True:
    now=a[now]-1
    order.append(now)
    if check[now]:
        break
    else:
        check[now]=True
order2=[]
now=order[-1]
while True:
    now=a[now]-1
    order2.append(now)
    if now==order[-1]:
        break
if k<=len(order):
    print(order[k-1]+1)
else:
    k-=len(order)
    x=k%len(order2)
    print(order2[x-1]+1)
