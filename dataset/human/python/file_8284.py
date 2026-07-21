import sys
N,*A = map(int, open(0).read().split())
S = (N+1)*N//2
if sum(A)%S!=0:
  print('NO')
  sys.exit()
M = sum(A)//S
B = [A[(i+1)%N]-A[i]-M for i in range(N)]
X = 0
for c in B:
  if c%(-N)!=0 or M<c:
    print('NO')
    break
  X += c//(-N)
else:
  if X==M:
    print('YES')
  else:
    print('NO')
