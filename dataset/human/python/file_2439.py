import math

D, G = map(int, input().split())
pn = []
s_max = []
for i in range(1, D+1):
  p, c = map(int, input().split())
  s_max.append(100*i*p+c)
  pn.append(p)

min = 10 ** 9
for i in range(2**(D)):
  count = 0
  p_count = 0
  no_solve = []
  for j in range(D):
    if i>>j&1 == 1:
      count += s_max[j]
      p_count += pn[j]
    else:
      no_solve.append(j)
  if count >= G:
    if min > p_count:
      min = p_count
  else:
    box = math.ceil((G - count) / (100 * (no_solve[-1]+1)))
    if box < pn[no_solve[-1]]:
      p_count += box
      if min > p_count:
        min = p_count
print(min)
