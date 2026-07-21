from collections import Counter

N = int(input())

def prime_factorize(n):
  a = []
  while n % 2 == 0:
    a.append(2)
    n //= 2
  f = 3
  while f * f <= n:
    if n % f == 0:
      a.append(f)
      n //= f
    else:
      f += 2
  if n != 1:
    a.append(n)
  return a

facts = Counter(prime_factorize(N))
cnt = 0

def pattern_cnt(n):
  res = 0
  cur = 1
  while n - cur >= 0:
    n -= cur
    res += 1
    cur += 1
  return res

for k in facts:
  cnt += pattern_cnt(facts[k])
  #print(k, cnt)

print(cnt)
