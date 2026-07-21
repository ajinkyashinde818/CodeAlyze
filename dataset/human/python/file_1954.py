N,M = map(int,input().split())
A = list()
B = list()
for i in range(N):
  A.append(input())
for i in range(M):
  B.append(input())
def check(posx, posy):
  for y in range(M):
    for x in range(M):
      if not B[y][x] == A[y + posy][x + posx]:
        return False
  return True
for y in range(N - M + 1):
  for x in range(N - M + 1):
    if check(x,y):
      print("Yes")
      exit()
print("No")
