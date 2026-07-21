MOD = 10 ** 9 + 7

def solve():
  N = int(input())
  S = [s == 'W' for s in input()] # W: True, B: False
  if S[0] or S[2 * N - 1]: return 0

  ans = 1
  cnt = 1
  d = True # L: True, R: False
  for i in range(1, N * 2):
    if S[i] == S[i - 1]: d = not d
    if d: cnt += 1
    else:
      ans = (ans * cnt) % MOD
      cnt -= 1

  if cnt != 0: return 0

  for i in range(2, N + 1): ans = (ans * i) % MOD
  return ans

print(solve())
