N = int(input())
A = list(map(int, input().split()))
if N == 2:
  ans = abs(A[0]-A[1])
else:
  import numpy
  s = numpy.cumsum(A)
  sA = s[-1]
  ar = numpy.abs(sA-s-s)
  ans = min(ar[1:N-1])
print(ans)
