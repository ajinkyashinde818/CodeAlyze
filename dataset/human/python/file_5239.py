from collections import defaultdict
d=defaultdict(list)
n,m=map(int,input().split())
for s in range(m):
  a,b=map(int,input().split())
  d[a].append(b)
for s in d[1]:
  if n in d[s]:print("POSSIBLE");exit()
print("IMPOSSIBLE")
