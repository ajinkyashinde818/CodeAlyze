import sys
n, m = map(int, input().split())
a = [list(input()) for i in range(n)]
b = [list(input()) for i in range(m)]
for i in range(n-m+1):
  for j in range(n-m+1):
    flag = False
    tmp = [a[f][j:j+m] for f in range(i, i+m)]
    for k in range(m):
      for l in range(m):
        if tmp[k][l] != b[k][l]:
          flag = True
          break
      if flag:
        break
    if flag:
      continue
    print("Yes")
    sys.exit()
print("No")
