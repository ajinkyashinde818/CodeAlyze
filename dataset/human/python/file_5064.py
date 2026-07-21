import sys
input=sys.stdin.readline
n,m=map(int,input().split())
tr=[[] for i in range(n+1)]
for i in range(m):
  a,b=map(int,input().split())
  if a!=1 and b!=n:
    continue
  if a==1:
    if tr[b]==[n]:
      print("POSSIBLE")
      exit()
    else:
      tr[b].append(a)
  if b==n:
    if tr[a]==[1]:
      print("POSSIBLE")
      exit()
    else:
      tr[a].append(b)
else:
  print("IMPOSSIBLE")
