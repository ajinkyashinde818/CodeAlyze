import bisect
N = int(input())
A = [int(i) for i in input().split()]
A.sort()
idx = bisect.bisect_left(A,0)
ans = 0
if idx%2 == 0:
  ans += abs(sum(A[0:idx]))
  if N > idx:
    ans += sum(A[idx:])
else:
  ans += abs(sum(A[0:idx-1]))
  if idx < N:
    ans += abs(A[idx-1]+A[idx])
  elif idx == N:
    ans += A[idx-1]
  if idx + 1 < N:
    ans += sum(A[idx+1:])
print(ans)
