N, M  = map(int, input().split())
A = [ input() for i in range(N)]
B = [ input() for i in range(M)]


def serch(x0, y0):
  for i in range(M):
    for j in range(M):
      if x0+i >= N or y0+j >= N:
        return False
      if A[x0+i][y0+j] != B[i][j]:
        return False
  return True

if M > N:
  print('No')
  exit()


for x in range(N):
  for y in range(N):
    if not serch(x,y):
      continue
    else:
      print('Yes')
      exit()
print('No')
