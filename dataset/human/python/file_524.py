import sys
input = sys.stdin.readline
n = int(input())
a = [int(i) for i in input().split()]
cnt = 0
ans = [abs(i) for i in a]
s = sum(ans)
mm = min(ans)

for i in a:
  if i < 0:
    cnt += 1

if mm == 0 or cnt%2 == 0:
  print(s)
else:
  print(s-mm*2)
