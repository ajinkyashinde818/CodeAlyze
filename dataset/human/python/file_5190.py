from collections import deque
import sys
input = sys.stdin.readline

N, M = map(int, input().split())
ship = [[] for i in range(N)]
for i in range(M):
  a,b = map(int, input().split())
  a -= 1
  b -= 1
  ship[a].append(b)
visited = []
for i in ship[0]:
  visited.append(i)
  for j in ship[i]:
    visited.append(j)

if N-1 in visited:
  print("POSSIBLE")
else:
  print("IMPOSSIBLE")
