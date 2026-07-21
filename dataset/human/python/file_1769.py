N, M = map(int, input().split())
n = []
m = []
for i in range(N):
  s = str(input())
  row = []
  for j in range(N):
    if s[j] == "#":
      row.append(1)
    else:
      row.append(0)
  n.append(row)
for i in range(M):
  s = str(input())
  row = []
  for j in range(M):
    if s[j] == "#":
      row.append(1)
    else:
      row.append(0)
  m.append(row)
 
def search(a,b):
  mr = mc = 0
  for r in range(a, a+M):
    for c in range(b, b+M):
      if n[r][c] != m[mr][mc]:
        return False
      mc += 1
    mr += 1
    mc = 0
  return True

ans = 0
for i in range(N-M+1):
  for j in range(N-M+1):
    if search(i,j):
      ans = 1
      break
  if ans:
    break
if ans:
  print("Yes")
else:
  print("No")
