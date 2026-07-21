import sys

while 1:
  n = input() + 1
  if n==1: break
  N = range(n)
  M = [0] * n
  y = [0] * n
  for i in N[1:]:
    x = [0] * n
    A = ' ' + raw_input()
    for j in N[1:]:
      if A[j] == '.': x[j] = min(y[j-1],y[j],x[j-1]) + 1
    M[i]=max(x)
    y = x
  print max(M)
