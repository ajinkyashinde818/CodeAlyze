from fractions import gcd


x,y = map(int, input().split())


def gcd(x, y):
  b = max(x, y)
  s = min(x, y)
  r = b % s
  while r != 0:
    b = s
    s = r
    r = b % s
  return s
 
def lcm(x, y):
  return (x * y) // gcd(x,y)


ans = lcm(x,y)

print(ans)
