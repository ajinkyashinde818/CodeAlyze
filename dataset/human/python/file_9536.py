import sys
readline = sys.stdin.readline

N,K = map(int,readline().split())
A = [0] + list(map(int,readline().split()))

pos = 1

while K:
  if K & 1:
    pos = A[pos]
  A = [A[A[i]] for i in range(N + 1)]
  K >>= 1
  
print(pos)
