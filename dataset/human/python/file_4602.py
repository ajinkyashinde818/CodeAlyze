N = int(input())
import sys
nn = [0 for _ in range(10**5+3)]
for _ in range(N):
  a,b = map(int,input().split())
  nn[a] += 1
  nn[b+1] -= 1
ans = 0
sss = 1
for i in range(len(nn)):
  sss += nn[i]
  if i <= sss:
    ans = i
print(ans-1)
