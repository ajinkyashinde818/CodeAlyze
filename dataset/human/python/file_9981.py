def gcd(m,n):
  x = max(m,n)
  y = min(m,n)
  if x % y == 0:
    return y
  else:
    while x % y != 0:
      z = x % y
      x = y
      y = z
    else:
      return z

def lcm(m,n):
  return int((m*n)/gcd(m,n))

numbers = input().split(" ")
num1 = int(numbers[0])
num2 = int(numbers[1])
print(lcm(num1,num2))
