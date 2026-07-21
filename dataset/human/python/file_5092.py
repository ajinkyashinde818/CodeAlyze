import sys
import bisect
N,M=map(int,input().split())
grid = []
for i in range(M):
    array = list(map(int, input().strip().split(' ')))
    grid.append(array)
pre = []
pos = []
for ships in grid:
  if ships[0] == 1:
    pre.append(ships[1])
  if ships[1] == N:
    pos.append(ships[0])
if pre == [] or pos == []:
  print('IMPOSSIBLE')
  sys.exit()
pre.sort()
pos.sort()
def index(a, x):
    'Locate the leftmost value exactly equal to x'
    i = bisect.bisect_left(a, x)
    if i != len(a) and a[i] == x:
        return 1
    return 0
for nums in pre:
  if index(pos,nums) == 1:
    print('POSSIBLE')
    sys.exit()
print('IMPOSSIBLE')
