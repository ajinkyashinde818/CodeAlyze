import math
def solve():
  n,k,s = (int(i) for i in input().split())
  query = [10**9]*n
  for i in range(k):
    query[i] = s
  if s != 10**9:
    print(*query)
  else:
    for i in range(n-k):
      query[i] = 1
    print(*query)
solve()
