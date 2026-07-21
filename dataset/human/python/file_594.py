import heapq
n=int(input())
a=list(map(int,input().split()))

zero_count=0
minus_count=0
for i in range(n):
    if a[i]<0:
        minus_count+=1
    if a[i]==0:
        zero_count+=1
        break

for i in range(n):
    a[i]=abs(a[i])

if zero_count==1 or minus_count%2==0:
    ans=sum(a)
else:
    heapq.heapify(a)
    mn=heapq.heappop(a)
    ans=sum(a)-mn

print(ans)
