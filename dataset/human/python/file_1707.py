N,M=map(int,input().split())
A=[list(input()) for i in range(N)]
B=[list(input()) for i in range(M)]
def AB(h,w):
  ret=[[None]*M for i in range(M)]
  for i in range(M):
    for j in range(M):
      ret[i][j]=A[h+i][w+j]
  return ret
ans='No'
for h in range(N-M+1):
  for w in range(N-M+1):
    if AB(h,w)==B:
      ans='Yes'
      break
print(ans)
