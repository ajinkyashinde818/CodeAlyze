import itertools
n,m=map(int,input().split())
AB=[list(map(int,input().split())) for _ in range(m)]

next=set()
for a,b in AB:
  if a==1:
    next.add(b)
for a,b in AB:
  if a in next and b==n:
    print('POSSIBLE')
    exit()
print('IMPOSSIBLE')
