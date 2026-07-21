import sys
 
stdin = sys.stdin
 
ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))
ns = lambda: stdin.readline()
 
k, s = na()

count = 0
for x in range(k+1):
  for y in range(k+1):
      if s-x-y >= 0 and s-x-y <= k:
        count += 1
print(count)
