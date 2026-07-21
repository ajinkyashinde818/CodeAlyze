N,M=map(int,input().split())
A = [str(input()) for _ in range(N)]
B = [str(input()) for _ in range(M)]
k=N//M + N%M
def macthing(y,x):
  flag=0
  for p in range(M):
    if A[y+p][x:x+M]!=B[p]:
      flag=1
      break
  if flag==0:
    return True
  else:
    return False

for i in range(k):
  for j in range(k):
    if macthing(i,j):
      print('Yes')
      exit()
print('No')
