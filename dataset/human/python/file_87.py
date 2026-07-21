import math
r,g,b,n = [int(u) for u in input().split(" ")]
i = 0
for ir in range(math.floor(n/r)+1):
  if ir*r==n:
    i+=1
    break
  elif ir*r>n:
    break
  for ig in range(math.floor(n/g)+1):
    y = n - (ir*r+ig*g)
    if y<0:
      break
    if y%b==0:
      #print(ir,ig,y/b)
      i+=1
      continue
print(i)
