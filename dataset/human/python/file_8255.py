import sys
input = sys.stdin.buffer.readline
N = int(input())
a = list(map(int, input().split()))
d = [0] * N
for i in range(1, N):
  d[i] = a[i] - a[i - 1]
d[0] = a[0] - a[-1]
if sum(a) % (N * (N + 1) // 2):
  print("NO")
  exit(0)
f = 0
m = sum(a) // (N * (N + 1) // 2)
c = 0
for i in range(N):
  if m - d[i] < 0 or (m - d[i]) % N:
    f = 0
    break
  c += (m - d[i]) // N
  if c == m:
    f = 1
  else: f = 0
if c == 0:
  r = m
if c > m:
  l = m
if f:
  print("YES")
else: print("NO")
