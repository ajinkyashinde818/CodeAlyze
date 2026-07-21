from collections import defaultdict
n,m=map(int,input().split())
ab=defaultdict(lambda: [])
for i in range(m):
  a,b=map(int,input().split())
  ab[a].append(b)
for aa in ab[1]:
  for bb in ab[aa]:
    if bb == n:
      print("POSSIBLE")
      exit()
print("IMPOSSIBLE")
