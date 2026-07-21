from functools import reduce
from operator import add

n = int(input())
lst = list(map(int, input().split()))

m = 0 #-の個数
z = 0 #0の個数

for i in range(n):
  if lst[i] == 0:
    z += 1
  if lst[i] < 0:
    m += 1

ans = 0
l = list(map(abs, lst))
if m%2 == 1 and z == 0:
  ans = reduce(add,l) - 2 * min(l)
else:
  ans = reduce(add,l)
print(ans)
