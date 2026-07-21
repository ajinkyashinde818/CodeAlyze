import math

D, G = [int(x) for x in input().split()]
P = [[int(x) for x in input().split()] for i in range(D)]

min_ = 1e+8
for bit in range(2**D):
  score = 0
  n_solved = 0
  rest = -1
  for i in range(D):
    if bit >> i & 1: 
      score += (i + 1) * 100 * P[i][0] + P[i][1]
      n_solved += P[i][0]
    else:
      rest = i
  if G > score:
    s1 = 100 * (rest + 1)
    need = (G - score + s1 - 1) // s1
    if need >= P[rest][0]:
      continue
    n_solved += need
  min_ = min(min_, n_solved)
print(min_)
