N,M=map(int,input().split())
A=[list(input()) for _ in range(N)]
B=[list(input()) for _ in range(M)]

def match(ii,jj):
  res=1
  for i in range(M):
    if A[i+ii][jj:jj+M]!=B[i]:
      res=0
      break
  return res

ans="No"
for i in range(N-M+1):
  for j in range(N-M+1):
    if match(i,j)==1:
      ans="Yes"
      break
  else:
    continue
  break

print(ans)
