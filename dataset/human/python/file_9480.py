from collections import deque
n,k = map(int, input().split())
a=[-1]
a.extend(list(map(int, input().split())))
route=[-1]*(n+1)
q=deque([1])
cnt=0
roop=0
while q:
  p=q.pop()
  route[p]=cnt
  if route[a[p]] == -1:
    q.append(a[p])
    cnt+=1
  else:
    roop=[route[a[p]],route[p]]
    break

if k <= min(roop):
  for i,r in enumerate(route[1:],start=1):
    if r == k:
      print(i)
else:
  t=(k-min(roop))%(max(roop)-min(roop)+1)
  for i,r in enumerate(route[1:],start=1):
    if r == t+min(roop):
      print(i)
