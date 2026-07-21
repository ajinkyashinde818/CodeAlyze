import sys
n = int(input())
s = input()
if s[0] == "W":
  print(0)
  sys.exit()
MOD = 10**9+7
ans = 1
cnt = 1
right = 1
for i in range(2*n-1):
  if s[i+1] == s[i]:
    right ^= 1
  if right:
    cnt += 1
  else:
    ans *= cnt
    ans %= MOD
    cnt -= 1
if cnt != 0:
  print(0)
else:
  for i in range(1, n+1):
    ans *= i
    ans %= MOD
  print(ans)
