from itertools import combinations
N = int(input())
S = list(input().strip())
d = {}
for c in S:
  if c in d.keys():
    d[c] += 1
  else:
    d[c] = 1
ans = 0
for n in d.values():
  ans = (ans+n+ans*n)%(10**9+7)
print(ans)
