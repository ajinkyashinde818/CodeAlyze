def hasB(A, B, M, x, y):
  has = True
  for i in range(M):
    for j in range(M):
      if A[y + i][x + j] != B[i][j]:
        has = False
  return has


N, M = list(map(lambda x: int(x), input().split(" ")))
A = []
B = []
for i in range(N):
  A.append(list(input()))
for j in range(M):
  B.append(list(input()))

has = False
for i in range(N - M + 1):
  for j in range(N - M + 1):
    if A[i][j] == B[0][0]:
      has = hasB(A, B, M, j, i)
      if has:
        break
  else:
    continue
  
  break

print("Yes") if has else print("No")
