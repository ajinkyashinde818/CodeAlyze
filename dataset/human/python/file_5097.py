from collections import defaultdict
N,M=map(int,input().split())
B=[list(map(int,input().split())) for _ in range(M)]
dic=defaultdict(list)
ans="IMPOSSIBLE"
for i,j in B:
  dic[i].append(j)
O=dic.get(1)
if N in O:
    ans="POSSIBLE"
for o in O:
  T=dic.get(o)
  try:
    if N in T:
      ans="POSSIBLE"
  except:
    pass
print(ans)
