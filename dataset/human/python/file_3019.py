import collections
from itertools import accumulate
from operator import add
import bisect

N = int(input())

def primef(n):
  i = 2
  p_nums = []
  while i * i <= n:
    while n % i == 0:
      n /= i
      p_nums.append(i)
    i += 1
  if n > 1:
    p_nums.append(int(n))
  return p_nums

ans = primef(N)
ans = dict((collections.Counter(ans)))
con = 0

acadd = list(accumulate(range(1,30),add))

for k in ans.values():
  con += bisect.bisect_right(acadd,k)
    
print(con)
