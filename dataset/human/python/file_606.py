import fractions
def solve():
  n = int(input())
  a = list(int(i) for i in input().split())
  flip = 0
  for i in range(n):
    if a[i] <0:
      a[i] *= -1
      flip += 1
  if flip %2 == 0:
   print(sum(a))
  else:
   print(sum(a)-2*min(a))
solve()
