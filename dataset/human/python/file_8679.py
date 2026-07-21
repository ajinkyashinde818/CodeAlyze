import math 
k,n = map(int , input().split())
a = list(map(int , input().split()))
ans = 0
for i in range(0,n-1):
  ans = max(ans,abs(a[i] - a[i+1]))

ans = max(ans,abs(k + a[0] - a[-1]))
print(k - ans)
