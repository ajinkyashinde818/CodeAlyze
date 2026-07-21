n, m = map(int, input().split())

a = [list(input()) for _ in range(n)]
b = [list(input()) for _ in range(m)]

import sys

for r in range(n - m + 1):
  for c in range(n - m + 1):
    for x in range(m):
      if a[r+x][c:c+m] != b[x][:]:
        break
    else:
      print("Yes")
      sys.exit()

print("No")
