import sys
from collections import defaultdict
d = defaultdict(int)

N, M = map(int, input().split())
li = [list(map(int, input().split())) for n in range(M)]

for i in li:
  if i[1] == N:
    d[i[0]] += 1

for i in li:
  if i[0] == 1 and d[i[1]] != 0:
    print("POSSIBLE")
    sys.exit()
    
print("IMPOSSIBLE")
