N, M = map(int, input().split())
A = [input() for _ in range(N)]
B = [input() for _ in range(M)]
ans = 'No'
def match(i, j):
  for k in range(M):
    for l in range(M):
      if A[i+k][j+l] != B[k][l]:
        return False
  return True
for i in range(N-M+1):
  for j in range(N-M+1):
    if match(i, j):
      ans = 'Yes'
      break
print(ans)
