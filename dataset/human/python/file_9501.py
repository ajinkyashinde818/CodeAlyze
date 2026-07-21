import sys
n,k=map(int,input().split())
a=list(map(int,input().split()))
visited=[0]*n
town=0
Town=0
visited[0]=0
lst=[]
if a[0]==1:
  print(1)
  sys.exit()
for i in range(n):
  town=a[town]-1
  if visited[town]!=0 or town==0:
    lst.append([town,visited[town],i+1])
    break
  else:
    visited[town]=i+1
Lst=[]
town=lst[0][0]
Lst.append(town)
if lst[0][2]-lst[0][1]-1==0:
  if k<lst[0][1]:
    print(visited.index(k)+1)
    sys.exit()
  else:
    print(lst[0][0]+1)
    sys.exit()
for i in range(lst[0][2]-lst[0][1]-1):
  town=a[town]-1
  Lst.append(town)
if k<=lst[0][1]:
  print(visited.index(k)+1)
else:
  k=k-lst[0][1]
  l=len(Lst)
  k=k%l
  print(Lst[k]+1)
