import math
k, n = map(int,input().split())
a = list(map(int,input().split()))

ans = 10**9
for i in range(n):
  if i == 0:
    a1 = a[-1]-a[0]
    a2 = a[0]+(k-a[1])
    ans = min(ans,a1,a2)
  else:
    a1 = (k-a[i])+a[i-1]
    ans = min(ans,a1)
print(ans)
