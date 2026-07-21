AB = input().split()
A = int(AB[0])
B = int(AB[1])

def gcd(m, n):
  x = max(m, n)
  y = min(m, n)
  if x%y ==0:
    return y
  else:
    while x%y!=0:
      z = x%y
      x = y
      y = z
    else:
      return z
 
def lcm(m, n):
  print(int(m * n /gcd(m, n)))

lcm(A, B)
