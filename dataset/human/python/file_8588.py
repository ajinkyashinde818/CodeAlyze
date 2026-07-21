import copy

k, n = map(int, input().split())
a = list(map(int, input().split()))

now = 0
ans = 2000000000000000000000000

for i in range(1, n):
    now = k-a[i]+a[i-1]
    if now < ans:
      ans = now

if a[n-1]-a[0] < ans:
  ans = a[n-1]-a[0]
        
print(ans)
