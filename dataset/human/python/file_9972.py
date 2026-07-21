a, b = map(int, input().split())

def prime_factorize(n):
    a = []
    while n % 2 == 0:
        a.append(2)
        n //= 2
    f = 3
    while f * f <= n:
        if n % f == 0:
            a.append(f)
            n //= f
        else:
            f += 2
    if n != 1:
        a.append(n)
    return a

aa = prime_factorize(a)
bb = prime_factorize(b)

if aa == []:
  print(b)
elif bb == []:
  print(a)
else:
  outList = []
  for _ in range(len(aa)):
    
    while len(bb) >= 1 and bb[0] < aa[0]:
      outList.append(bb[0])
      bb.pop(0)
    
    if len(bb) == 0:
      break
   
    if aa[0] == bb[0]:
      outList.append(aa[0])
      aa.pop(0)
      bb.pop(0)
    elif aa[0] < bb[0]:
      outList.append(aa[0])
      aa.pop(0)
      
    if len(bb) == 0:
      break
      
  out = 1
  for i in range(len(outList)):
    out *= outList[i]
  for i in range(len(aa)):
    out *= aa[i]
  for i in range(len(bb)):
    out *= bb[i]
  print(out)
