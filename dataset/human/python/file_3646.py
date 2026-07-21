from bisect import bisect as bisect
l = [0]*100000
for i in range(len(l)):
    l[i] = (i*(i+1))//2

N = int(input())
def prime_decomposition(n):
  i = 2
  d = {}
  while i * i <= n:
    while n % i == 0:
      n //= i
      if i not in d:
          d[i] = 0
      d[i] += 1
    i += 1
  if n > 1:
    if n not in d:
        d[n] = 1
  return d

d = prime_decomposition(N)
ans = 0
for i in d:
    ans += bisect(l,d[i])-1
print(ans)
