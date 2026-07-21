n,m = map(int,input().split())
a = [input() for i in range(n)]
b = [input() for i in range(m)]
x = y = 0

def check(x,y):
  for i in range(m):
    if b[i] != a[y+i][x:x+m]:
      return(False)
  return(True)

for x in range(n-m+1):
  for y in range(n-m+1):
    if check(x,y):
      print("Yes")
      exit()
print("No")
