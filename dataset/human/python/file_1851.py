N,M=map(int,input().split())
A=[input() for i in range(N)]
B=[input() for i in range(M)]
def F(a,b):
  for k in range(M):
    for l in range(M):
      if A[a+l][b+k]!=B[l][k]:
        return False
  return True
  
for i in range(N-M+1):
  for j in range(N-M+1):
    if F(i,j):
      print('Yes')
      exit()
print('No')
