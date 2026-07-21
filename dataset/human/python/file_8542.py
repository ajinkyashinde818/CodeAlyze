import sys
readline = sys.stdin.readline

K,N = map(int,readline().split())
A = list(map(int,readline().split()))

ans = A[-1] - A[0] # K - ((K - A[-1]) + A[0])

for i in range(1,len(A)):
  if K - (A[i] - A[i - 1]) < ans:
    ans = K - (A[i] - A[i - 1])

print(ans)
