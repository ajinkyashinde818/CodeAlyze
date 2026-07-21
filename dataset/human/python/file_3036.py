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
def main():
  N = int(input())
  dic = collections.Counter(prime_factorize(N))
  ans = 0
  for pri, num in dic.items():
    total = 0
    e = 1
    while True:
      total = total + e
      if total > num:
        ans += e-1
        break
      e+=1
  print(ans)
if __name__ == "__main__":
  main()
