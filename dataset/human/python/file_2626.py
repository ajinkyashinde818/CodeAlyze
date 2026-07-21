import sys
sys.setrecursionlimit(pow(10, 6))

d, g = map(int, input().split())
pc = []
for _ in range(d):
  pc.append(tuple(map(int, input().split())))

def dfs(i, ll):
  if i != d:
    solve = dfs(i+1, ll + [1])
    nsolve = dfs(i+1, ll + [0])
    return min(solve, nsolve)
  else:
    total = sum((100 * (j + 1) * p + c) * l for j, ((p, c), l) in enumerate(zip(pc, ll)))
    if total >= g:
      return sum(p * l for (p, _), l in zip(pc, ll))
    else:
      rem = g - total
      remc = pow(10, 6)
      for j, ((p, c), l) in reversed(tuple(enumerate(zip(pc, ll)))):
        if l == 0:
          if rem > 100 * (j + 1) * (p - 1):
            break
          else:
            remc = rem // (100 * (j + 1)) + (1 if rem % (100 * (j + 1)) else 0)
            break
      return sum(p * l for (p, _), l in zip(pc, ll)) + remc

print(dfs(0, []))
