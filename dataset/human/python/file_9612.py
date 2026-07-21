from decimal import *

N,K = map(int,input().split())

A = list(map(int,input().split()))
visit = [0]*N
fi = [1]
st = 0
visit[0] = 1
p = A[0]
for i in range(N):
  fi.append(p)
  if visit[p-1] == 0:
    visit[p-1] = i+2
    p = A[p-1]
  else:
    
    st = i
    break
    
loop = []
loop.append(p)
q = p
while 1:
  if q == A[p-1]:
    break
  loop.append(A[p-1])
  p = A[p-1]
st-=len(loop)
fi = fi[:len(fi)-len(loop)-1]
if K - st> 0:
  k = (K - st) % len(loop)
  print(loop[k-1])
else:
  print(fi[K])
