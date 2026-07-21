N, M=map(int, input().split())
A=[input() for _ in range(N)]
B=[input() for _ in range(M)]

def f(i, j):
  for s in range(M):
    for t in range(M):
      if A[i+s][j+t]!=B[s][t]:
        return False
  return True

for i in range(N-M+1):
  for j in range(N-M+1):
    r=f(i, j)
    if r==True:
      print('Yes')
      exit()
print('No')
