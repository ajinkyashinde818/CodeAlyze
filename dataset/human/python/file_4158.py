from math import floor
from math import sqrt
N = int(input())
def f(x):
  return (floor((-1+sqrt(1+8*x))/2.0))
ans = 0
i = 2
while N > 1:
  x = 0
  while N % i == 0:
    N = N // i
    x = x + 1
  if x != 0:
    ans = ans + f(x)
  i = i + 1
  if i > 10 ** 6:
    ans = ans + 1
    break
print(ans)
