import sys
stdin = sys.stdin
sys.setrecursionlimit(10**6)
ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))
nn = lambda: list(stdin.readline().split())
ns = lambda: stdin.readline().rstrip()

s = ns()
ans = 0
r = 0
l = len(s)-1
while r < l:
  if s[r] == s[l]:
    r += 1
    l -= 1
  elif s[r] == "x":
    ans += 1
    r += 1
  elif s[l] == "x":
    ans += 1
    l -= 1
  else:
    print(-1)
    exit()

print(ans)
