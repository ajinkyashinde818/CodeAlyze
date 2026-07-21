import sys

def isin(y, x):
  flag = True
  for i in range(m):
    for j in range(m):
      if image_n[y + i][x + j] != image_m[i][j]:
        flag = False
        
  return flag 

n, m = list(map(int, input().split()))

image_n = []

for i in range(n):
  image_n.append(input())

image_m = []

for j in range(m):
  image_m.append(input())


for i in range(n - m + 1):
  for j in range(n - m + 1):
    if isin(i, j):
      print("Yes")
      sys.exit()

print("No")
