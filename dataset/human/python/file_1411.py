import sys
n = int (sys.stdin.readline())
a = map(int, sys.stdin.readline().split())

cur1 = a[0]
cur2 = sum(a) - cur1
res = 10 ** 15
for i in a[1:]:
  res = min (res, abs (cur1 - cur2))
  cur1 += i
  cur2 -= i
print res
