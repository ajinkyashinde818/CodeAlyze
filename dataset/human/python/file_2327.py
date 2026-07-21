d, g = map(int, input().split())
pc = [0] + [list(map(int, input().split())) for _ in range(d)]

def solve(g, d):
  if d == 0:
    return 10**9
  n = min(g//(100*d), pc[d][0])
  t = n * d * 100
  if n == pc[d][0]:
    t += pc[d][1]
  if t < g:
    n += solve(g-t, d-1)
  return min(n, solve(g,d-1))

print(solve(g,d))
