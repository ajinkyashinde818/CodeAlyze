import bisect
def factorization(n):
  m = {}
  _n = n
  for i in range(2, int(n ** (1/2)) + 1):
    if _n % i == 0:
      cnt = 0
      while _n % i == 0:
        _n //= i
        cnt += 1
      m[i] = cnt
  if _n != 1:
    m[_n] = 1
  return m

n = int(input())
m = factorization(n)

ans = 0
for _m in m:
  p = m[_m]
  _tri = 0
  _cnt = 0
  while p >= _tri:
    _cnt += 1
    _tri += _cnt
  ans += _cnt - 1

print(ans)
