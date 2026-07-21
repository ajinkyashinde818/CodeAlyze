import sys 

N,M  = map(int,input().split())
     
a = [[0 for i in range(2)] for j in range(M)]
b = [] 
c = []

for i in range(M):
  a[i][0] , a[i][1] = map(int,input().split())
  first, second = a[i][0],a[i][1]
  if first == 1:
    b.append(second)
  if second == N:
    c.append(first)

b_set = set(b)
c_set = set(c)

if list(b_set & c_set) is None or len(list(b_set & c_set)):
  res = ('POSSIBLE')
else:
  res = ('IMPOSSIBLE')

print(res)
