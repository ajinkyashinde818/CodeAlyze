import sys
sys.setrecursionlimit(10**9)

N, K = map(int, input().split())
A = [0] + list(map(int, input().split()))

stack = []
s = set()
def dfs(a, k):
  stack.append(a)
  s.add(a)
  if k == K:
    return a
  next_a = A[a]
  if next_a in s:
    idx = stack.index(next_a)
    i = (K - (k + 1)) % (k + 1 - idx)
    return stack[idx + i]
  else:
    res = dfs(next_a, k+1)
  return res

print(dfs(1, 0))
