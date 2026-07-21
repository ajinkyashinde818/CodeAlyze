from math import copysign
K,N = map(int,input().split())
A = list(map(int,input().split()))

max_dist = K - A[N-1] + A[0]
s = 0
for i in range(0,N-1):
  if max_dist < A[i+1] - A[i]:
    max_dist = A[i+1] - A[i]
    s = i + 1

B = list(map(lambda x: int(copysign(x+K, x)), A[:s]))
A = A[s:] + B

ans = 0
for j in range(N):
  if j == 0:
    continue
  ans += A[j] - A[j-1]
  
print(ans)
