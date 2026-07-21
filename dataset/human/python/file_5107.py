import sys
n,m=map(int,input().split())
a=[list(map(int,input().split())) for _ in range(m)]
b=set()
c=set()
for l in a:
  if l[0]==1:
    b.add(l[1])
  elif l[1]==n:
    c.add(l[0])
for x in b:
  if x in c:
    print("POSSIBLE")
    sys.exit()
print("IMPOSSIBLE")
