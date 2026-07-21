N, M = map(int, input().split())

f = lambda x: 1 if x == "#" else 0
A = [list(map(f, input())) for _ in range(N)]
B = [list(map(f, input())) for _ in range(M)]

def func():
  for i in range(N-M+1):
    for j in range(N-M+1):
      if all(A[i+k][j+l] == B[k][l] for k in range(M) for l in range(M)):
        return True
  return False

print("Yes" if func() else "No")
