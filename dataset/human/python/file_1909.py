import sys
n, m = map(int, input().split())
image = []
temp = []
match = False
for i in range(n):
  image.append(input())
for i in range(m):
  temp.append(input())
for i in range(n):
  for j in range(n - m + 1):
    if (temp[0] == image[i][j : j + m]):
      match = True
      for k in range(1, m):
        if (i + k >= n):
          match = False
          break
        elif (temp[k] != image[i + k][j : j + m]):
          match = False
          break
      if (match == True):
        print('Yes')
        sys.exit()
print('No')
