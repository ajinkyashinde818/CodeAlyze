N, M = map(int, input().split())

A = []
for i in range(N):
  A.append(input())
  
B = []
for i in range(M):
  B.append(input())
  
def match(a,b):
  for i in range(M):
    for j in range(M):
      if A[a+i][b+j] != B[i][j]:
        return False  
  return True

for i in range(N-M+1):
  for j in range(N-M+1):
    if match(i,j):
      print("Yes")
      exit(0)
      
print("No")
