N = int(input())
S = input()
MOD = 10**9 + 7

base = 1
unsettled = 0
remaining = 2 * N
for i, s in enumerate(S):
  if s == 'W':
    if unsettled % 2: # 奇数
      unsettled += 1
    else: # 偶数
      base = (base * unsettled) % MOD
      unsettled -= 1
  else: # s == 'B'
    if unsettled % 2: # 奇数
      base = (base * unsettled) % MOD
      unsettled -= 1
    else:
      unsettled += 1
  if unsettled < 0:
    print(0)
    quit()
  remaining -= 1
  if unsettled == remaining:
    break

for s in S[i+1:]:
  if s == 'W':
    if unsettled % 2: # 奇数
      print(0)
      quit()
    else: # 偶数
      base = (base * unsettled) % MOD
      unsettled -= 1
  else: # s == 'B'
    if unsettled % 2: # 奇数
      base = (base * unsettled) % MOD
      unsettled -= 1
    else: # 偶数
      print(0)
      quit()

def factorial(n, mod=10**9+7):
    a = 1
    for i in range(1,n+1):
        a = a * i % mod
    return a

print(base * factorial(N) % MOD)
