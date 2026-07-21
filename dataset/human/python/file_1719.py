import sys

n, m = map(int, input().split())
a = [input() for i in range(n)]
b = [input() for i in range(m)]

for i in range(n-m+1):
  for j in range(n-m+1):
    f = True
    for k in range(m):
      for l in range(m):
        if a[i+k][j+l] != b[k][l]:
          f = False
    if f == True:
      print("Yes")
      sys.exit()
      
print("No")
