import collections

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

def judge(N):
  n = 0
  cnt = 0
  while n < N:
    n += cnt+1
    if n<=N:
      cnt += 1
  return cnt


c = collections.Counter(prime_factorize(N))

ans = 0


keys = c.keys()

for i in range(len(keys)):
  ans += judge(c[list(keys)[i]])

print(ans)
