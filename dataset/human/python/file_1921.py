def matching(A, B, N, M) :
  if N == M : 
    for j in range(N) : 
      match = 0
      if A[j] != B[j] :
        break
      match += 1
    if match == M : 
      return True
    else :
      return False
  for i in range(N - M) : 
    for j in range(N - M) :
      match = 0
      for m in range(M) :
        if A[j + m][i : M + i] != B[m] :
          break
        match += 1
      if match == M : 
      	return True
  return False
      
          
N, M = tuple(map(int, input().split()))
A = list()
B = list()

for i in range(N) :
  A.append(input())
  
for i in range(M) :
  B.append(input())
  
if matching(A, B, N, M) :
  print('Yes')
else : 
  print('No')
