import sys
input = sys.stdin.readline
n = int(input())
s = input().rstrip()
mod = 10**9+7

from collections import Counter
c = Counter(s)
ans = 0
for i in s:
  chk = 1
  for j,v in c.items():
    if j == i:
      continue
    chk *= v+1
  ans += chk
  ans %= mod
  c.update({i:-1})
  
print(ans%mod)
