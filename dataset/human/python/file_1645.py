n,m=map(int,raw_input().split())
A=[raw_input() for j in range(n)]
B=[raw_input() for j in range(m)]
def sub(ox,oy):
  for x in xrange(m):
    for y in xrange(m):
      if A[ox+x][oy+y] != B[x][y]:
        return False
  return True
def match():
  for x in xrange(n-m+1):
    for y in xrange(n-m+1):
      if sub(x,y): return True
  return False
if match():
  print 'Yes'
else:
  print 'No'
