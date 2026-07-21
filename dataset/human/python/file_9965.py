x = input().split()
a = int(x[0])
b = int(x[1])

def gcd(s,t):
  if(s>=t):
    m = s
    n = t
  else:
    m = t
    n = s
  while True:
    if(m%n == 0):
      return n
    else:
      temp = n
      n = m % n
      m = temp

f = int(a*b/gcd(a,b))
print(f)
