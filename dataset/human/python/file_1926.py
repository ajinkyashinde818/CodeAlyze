n, m = map(int, input().split())
a = []
b = []
for _ in range(n):
  a.append(input())
for _ in range(m):
  b.append(input())

def detect(i, j):
  flag = True
  for k in range(len(b)):
    for l in range(len(b)):
      if i+k >= n or j+l >= n or a[i+k][j+l] != b[k][l]:
        flag = False
        break
    if not flag:
      break
  return flag
  
ans = "No"
for i in range(len(a)):
  for j in range(len(a)):
    if detect(i, j):
      ans = "Yes"
      break
  if ans == "Yes":
    break
print(ans)
