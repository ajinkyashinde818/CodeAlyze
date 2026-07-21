N,M=map(int,input().split())
A=[[] for i in range(N)]
B=[[] for j in range(M)]

for i in range(N):
  s=input().strip()
  A[i]=list(s)
for i in range(M):
  s=input().strip()
  B[i]=list(s)

def check(a,b):
  for i in range(M):
    for j in range(M):
      if A[i+a][j+b] != B[i][j]:
        return False
  return True

ch=False
for i in range(N-M+1):
  if ch:
    break
  for j in range(N-M+1):
    ch=check(i,j)
    if ch:
      break
if ch:
  print("Yes")
else:
  print("No")
