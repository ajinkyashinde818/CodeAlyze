import collections

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

def tmp(m):
  c = 0
  s = 0
  for i in range(1,m+1):
    if s + i > m:
      return c
    c = c + 1
    s = s + i
  
  return c

def main():
  N = int(input())
  c = collections.Counter(prime_factorize(N))
  multupliyer_list = c.values()
  count = 0
  for m in multupliyer_list:
    t = tmp(m)
    count = count + t

  print(count)


if __name__ == "__main__":
  main()
