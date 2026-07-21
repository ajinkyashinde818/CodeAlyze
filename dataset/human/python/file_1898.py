N, M = map(int, input().split())

A = [input() for _ in range(N)]
B = [input() for _ in range(M)]


def f(i, j):
  for k in range(M):
    for l in range(M):
      if A[i+k][j+l] != B[k][l]:
        return False
  return True

def slv():
  for i in range(N-M+1):
    for j in range(N-M+1):
      if f(i, j):
        return 'Yes'
  return 'No'
print(slv())
