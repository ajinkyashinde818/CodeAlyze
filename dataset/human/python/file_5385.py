from collections import deque
N, M = [int(x) for x in input().split()]
fst_to = deque([])
sec_from = deque([])
for a, b in [[int(x) for x in input().split()] for _ in range(M)]:
  if a == 1:
    fst_to.append(b)
  elif b == N:
    sec_from.append(a)
ret = 'IMPOSSIBLE'
if set(fst_to) & set(sec_from):
  ret = 'POSSIBLE'
print(ret)
