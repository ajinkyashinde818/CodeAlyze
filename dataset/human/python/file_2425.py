from itertools import combinations
inf = 1 << 30

d, g = [int(x) for x in input().split()]
p, c = zip(*[[int(x) for x in input().split()] for _ in range(d)])

def n_prob(l):
  t = sum([p[i]*(i+1)*100+c[i] for i in l])
  n = sum([p[i] for i in l])
  if t<g:
    for j in range(d-1, -1, -1):
      if j not in l:
        if t+p[j]*(j+1)*100 >= g:
          n += (g-t+(j+1)*100-1)//((j+1)*100)
          return n        
    return inf
  return n

print(min([n_prob(l) for x in range(d+1) for l in combinations(range(d), x) ]))
