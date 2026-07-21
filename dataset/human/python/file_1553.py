def ck(i,j):
  flag = True
  for a, b in zip(A[i:i+M], B):
    for aa, bb in zip(a[j:j+M], b):
      if aa != bb:
        flag = False
  return flag

f = False

N, M = map(int, input().split())
A = [input() for i in range(N)]
B = [input() for i in range(M)]

for i in range(N-M+1):
  for j in range(N-M+1):
    if A[i][j] == B[0][0]:
      if (ck(i,j)):
        f = True
        
if f:
  print("Yes")
else:
  print("No")
