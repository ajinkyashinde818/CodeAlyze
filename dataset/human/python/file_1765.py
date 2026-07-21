n,m = map(int,input().split())
a = [input() for i in range(n)]
b = [input() for i in range(m)]

def is_same(i,j):
  for l in range(m):
    for k in range(m):
      if a[i+l][j+k] != b[l][k]:
        return False
  return True
  
for i in range(n-m+1):
  for j in range(n-m+1):
    if is_same(i,j):
      print('Yes')
      exit()
print('No')
