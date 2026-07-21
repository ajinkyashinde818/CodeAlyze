n,m=map(int,input().split())
x='No'
a=[input() for _ in range(n)]
b=[input() for _ in range(m)]
def c(i,j):
  global m
  global a
  global b
  for k in range(m):
    for l in range(m):
      if b[k][l]!=a[i+k][j+l]:
        return 0
  return 1
for i in range(n-m+1):
  for j in range(n-m+1):
    if c(i,j)==1:
      x='Yes'
      break
print(x)
