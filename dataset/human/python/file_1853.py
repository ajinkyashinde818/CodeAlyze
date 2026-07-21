n, m = map(int, input().split())
a = [list(input()) for _ in range(n)]
b = [list(input()) for _ in range(m)]

def c(a, m, x, y):
  tmp = []
  for i in range(m):
    tmp.append(a[y+i][x:x+m])
  return tmp

for x in range(n - m + 1):
  for y in range(n - m + 1):
    if c(a, m, x, y) == b:
      print("Yes")
      exit(0)
print("No")
