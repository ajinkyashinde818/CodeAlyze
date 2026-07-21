import numpy as np

n, k = list(map(lambda x: int(x), input().split(' ')))
teles = list(map(lambda x: int(x)-1, input().split(' ')))

beforeloop = 0
loop = []

done = False

ni, nj = 0, 0
pi, pj = 0, 0
while True:
  pi = teles[pi]
  pj = teles[teles[pj]]
  ni += 1
  nj += 2
  # ni回, piにて確実にループ内
  # ループ一周は nj - ni(= ni)要素&回
  if ni == k:
    print(pi+1)
    done = True
    break
  if pi == pj:
    beforeloop = ni
    break
    
if not done:
  current = pi
  loop.append(current)
  while True:
    current = teles[current]
    if current == pi:
      break
    loop.append(current)
  print(loop[(k - beforeloop) % len(loop)]+1)
