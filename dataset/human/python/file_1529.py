import sys
n, m = map(int, input().split())
a = []
for i in range(n):
  a.append(list(input()))
b = []
for i in range(m):
  b.append(list(input()))
for i in range(n - m + 1):
  for j in range(n - m + 1):
    if [c[j:j+m] for c in a[i:i+m]] == b:
      print('Yes')
      sys.exit()
print('No')
