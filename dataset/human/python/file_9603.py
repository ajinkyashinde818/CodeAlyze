import sys
n, k=map(int,input().split())
a=list(map(int,input().split()))

alr=[False]*n
alr[0]=True
now_in=0

if k<=2*(10**5)+1:
    for i in range(k):
        now_in=a[now_in]-1
    print(now_in+1)
    sys.exit()

#ループのスタートを見つける
for i in range(n+1):
    now_in=a[now_in]-1
    if alr[now_in] is False:
        alr[now_in]=True
    else:
        start=now_in
        break

count_r=0
now_in=start
for i in range(2*(10**5)+1):
    now_in=a[now_in]-1
    count_r+=1
    if now_in==start:
        break

now_in=0
count=0
while now_in!=start:
    now_in=a[now_in]-1
    count+=1

c=k-count
plus=c%count_r
for i in range(plus):
    now_in=a[now_in]-1

print(now_in+1)
