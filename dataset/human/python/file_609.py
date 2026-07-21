import sys
sys.setrecursionlimit(1000000)

n = int(raw_input())
a = map(int, raw_input().split())

memo = dict()
def dp(pos, flag):
  if pos == n - 1:
    if flag == 0:
      return a[pos]
    else:
      return -a[pos]
  if (pos, flag) in memo:
    return memo[(pos, flag)]
  elif flag == 0:
    memo[(pos, flag)] = max(dp(pos + 1, 0) + a[pos], dp(pos + 1, 1) - a[pos])
    return memo[(pos, flag)]
  else:
    memo[(pos, flag)] = max(dp(pos + 1, 0) - a[pos], dp(pos + 1, 1) + a[pos])
    return memo[(pos, flag)]
print dp(0, 0)
