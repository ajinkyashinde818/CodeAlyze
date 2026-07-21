from collections import defaultdict

def prime_factorize(n):
  a = defaultdict(int)
  while n % 2 == 0:
    a[2] += 1
    n //= 2
  f = 3
  while f * f <= n:
    if n % f == 0:
      a[f] += 1
      n //= f
    else:
      f += 2
  if n != 1:
    a[n] += 1
  return a

def calc(i):
  c = 1;
  acc = 0;
  count = 0
  while acc < i:
    acc += c
    c += 1
    if acc<=i:
      count+=1
  return count;

def main():
  n = int(input())
  if(n==1):
    print(0)
    return;
  facts = prime_factorize(n)
  count = 0
  for fact in facts:
    count += calc(facts[fact])
  print(count)

main()
