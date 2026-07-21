n = int(input())
xs = [int(c) for c in input().split()]
ys = [int(c) for c in input().split()]

def dp(x, y, mods):
  if y > x:
    return False
  table = [False] * (x + 1)
  table[x] = True
  mods.sort(reverse=True)
  for mod in mods:
    for i in range(x + 1):
      table[i % mod] = table[i % mod] or table[i]
  return table[y]

def ok(mods):
  return all(dp(x, y, list(mods)) for x, y in zip(xs, ys))

if not ok(range(1, 51)):
  print(-1)
  quit(0)

mods = []
for mod in range(50, 0, -1):
  if not ok(mods + list(range(1, mod))):
    mods.append(mod)

print(sum(2 ** mod for mod in mods))
