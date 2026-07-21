import math

n = int(input())

if n==1:
  print(0)
else:
  fctr = []
  for a in range(2,math.isqrt(n)+1):
    atta = 0
    if n%a==0:
      while n%a==0:
        atta += 1
        n //= a
      fctr.append((a,atta))
  if n!=1:
    fctr.append((n,1))
#  print(fctr)

  kaisu = 0
  for pair in fctr:
    if pair[1]<3:
      kaisu += 1
    elif pair[1]<6:
      kaisu += 2
    elif pair[1]<10:
      kaisu += 3
    elif pair[1]<15:
      kaisu += 4
    elif pair[1]<21:
      kaisu += 5
    elif pair[1]<28:
      kaisu += 6
    elif pair[1]<36:
      kaisu += 7
    elif pair[1]<45:
      kaisu += 8
    elif pair[1]<55:
      kaisu += 9

  print(kaisu)
