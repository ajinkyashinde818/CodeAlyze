def factorization(n):
  arr = []
  temp = n
  for i in range(2, int(-(-n**0.5//1))+1):
    if temp%i==0:
      cnt=0
      while temp%i==0:
        cnt+=1
        temp //= i
      arr.append([i, cnt])

  if temp!=1:
    arr.append([temp, 1])

  if arr==[]:
    arr.append([n, 1])

  return arr

n = int(input())
a = factorization(n)
c = 0
if n == 1:
  print(0)
  exit()
for d in a:
  s = d[1]
  if s > 44:
    c += 9
  elif s > 35:
    c += 8
  elif s > 27:
    c += 7
  elif s > 20:
    c += 6
  elif s > 14:
    c += 5
  elif s > 9:
    c += 4
  elif s > 5:
    c += 3
  elif s > 2:
    c += 2
  elif s > 0:
    c += 1
print(c)
