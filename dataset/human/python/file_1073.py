import sys
import heapq
hpush = heapq.heappush
hpop = heapq.heappop
input = sys.stdin.readline
N = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
ca = [0] * (N + 1)
cb = [0] * (N + 1)
for x in a: ca[x] += 1
for x in b: cb[x] += 1
for i in range(1, N + 1):
  if ca[i] + cb[i] > N:
    print("No")
    exit(0)

res = [0] * N
h = []
for i in range(1, N + 1):
  if cb[i]:
    r = N - ca[i] - cb[i] + 1
    hpush(h, (r, i))
#print(h)
s = []
table = [0] * (N + 1)
use = [0] * (N + 1)
for i in range(N):
  table[a[i]] += 1
  if len(s) and s[-1] != a[i]:
    x = s.pop()
    hpush(h, (N - ca[x] - cb[x] + 1 + table[x] + use[x], x))
  if len(h) == 0:
    print("No")
    exit(0)
  r, x = hpop(h)
  if x == a[i]:
    s.append(x)
    if len(h) == 0:
      print("No")
      exit(0)
    r, x = hpop(h)
  while r != N - ca[x] - cb[x] + 1 + table[x] + use[x]:
    hpush(h, (N - ca[x] - cb[x] + 1 + table[x] + use[x], x))
    r, x = hpop(h)
  res[i] = x
  use[x] += 1
  if cb[x] - use[x]: hpush(h, (r + 1, x))
  #print(res, h, s)
for i in range(N):
  if res[i] == a[i]:
    print("No")
    break
else:
  print("Yes")
  print(*res)
