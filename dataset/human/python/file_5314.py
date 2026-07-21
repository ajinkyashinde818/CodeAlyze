from collections import defaultdict
N, M = map(int, input().split())

shima = []
ans = "IMPOSSIBLE"

for i in range(M):
  a,b = map(int ,input().split())
  if a == 1: shima.append(b-1)
  if b == N: shima.append(a-1)
    
shima.sort()
for s,t in zip(shima[:-1],shima[1:]):
  if s == t:
    ans = "POSSIBLE"
    break
 
print(ans)
