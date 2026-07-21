import sys
n,m=map(int,input().split())
l=[[int(i) for i in l.split()] for l in sys.stdin]
possible=[]
possible2=[]
for i in l:
  if i[0]==1:
    possible.append(i[1])
for i in l:
  if i[1]==n:
    possible2.append(i[0])
if len(set(possible)&set(possible2))>0:
  print('POSSIBLE')
else:
  print('IMPOSSIBLE')
