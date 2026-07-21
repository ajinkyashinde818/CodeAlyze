import sys
import itertools

n, k = map(int, sys.stdin.readline().split())
a = list(map(int, sys.stdin.readline().split()))
a_len = len(a) - 1

b = [1]
labeled = set(b)
index = 1
loop_start = 0
while len(labeled) <= a_len:
  p = a[index - 1]
  if p in labeled:
    loop_start = b.index(p)
    break
  labeled.add(p)
  b.append(p)
  index = p
#print(f'{b=}')
#print(f'{loop_start=}')

loop_len = len(b) - loop_start
#print(f'{loop_len=}')

if k < len(b) - 1:
  print(b[k])
else:
  kk = k - loop_start
  # print(f'{kk=}')
  kk %= loop_len
  # print(f'{kk=}')
  kk += loop_start
  # print(f'{kk=}')

  print(b[kk])
