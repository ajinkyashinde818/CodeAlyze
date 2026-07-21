import sys
n,m=map(int,input().split())
lst=[]
chukei=[]
for i in range(m):
  a,b=map(int,input().split())
  if a==1:
    lst.append(b)
  if b==n:
    chukei.append(a)
X=lst+chukei
if len(set(X))==len(lst)+len(chukei):
  print('IMPOSSIBLE')
else:
  print('POSSIBLE')
