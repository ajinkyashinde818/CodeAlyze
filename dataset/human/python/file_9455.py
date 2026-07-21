N,K = map(int, input().split())
A = [int(c) for c in input().split()]
cnt = 0
p = 0
used = [False]*N
used[0] = True
while True:
  p = A[p]-1
  cnt += 1
  if used[p]:
    m = p
    break
  used[p] = True
p = 0
while m!=p and K:
  cnt -= 1
  p = A[p]-1
  K -= 1
if K==0:
  print(p+1)
  import sys
  sys.exit()
K %= cnt
while K:
  p = A[p]-1
  K -= 1
print(p+1)
