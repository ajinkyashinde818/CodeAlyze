from heapq import heappush,heappop

N = int(input())
array = list(map(int,input().split()))
nega = []
posi = []

for num in array:
  if num >= 0:
    heappush(posi,num)
  else:
    heappush(nega,num*(-1))


if len(nega)%2==0:
  ans = sum(nega) + sum(posi)
else:
  if len(nega)==N:
    max_nega = heappop(nega)
    ans = sum(nega) - max_nega
  else:
    min_posi = heappop(posi)
    max_nega = heappop(nega)
    if min_posi > max_nega:
      ans = sum(nega) + sum(posi) + min_posi - max_nega
    else:
      ans = sum(nega) + sum(posi) - min_posi + max_nega

print(ans)
