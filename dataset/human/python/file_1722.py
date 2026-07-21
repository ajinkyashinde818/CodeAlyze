N,M=map(int,input().split())
gridA=[None]*N
gridB=[None]*M
for i in range(N):
  gridA[i]=input()
for i in range(M):
  gridB[i]=input()

def isMatch(y,x):
  for i in range(M):
    for j in range(M):
      if gridB[i][j]!=gridA[y+i][x+j]:
        return False
  return True

for i in range(N-M+1):
  for j in range(N-M+1):
    if isMatch(i,j):
      print("Yes")
      exit(0)
print("No")
