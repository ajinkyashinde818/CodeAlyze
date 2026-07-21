from collections import Counter


def pf(x):
  if x == 1:
    return []
  r = []
  while not x & 1:
    r += [2]
    x >>= 1
  i = 3
  m = int(x ** 0.5)
  while i < m + 1:
    while not x % i:
      r += [i]
      x //= i
    i += 2
  if x != 1:
    r += [x]
  return r


def main():
  n = int(input())
  
  pp = pf(n)
 
  cc = Counter(pp)
  
  res = 0
  
  for c, v in cc.items():
    i = 1
    while True:
      if i > v:
        break
      v -= i
      res += 1
      i += 1
      
  print(res)


if __name__ == "__main__":
  main()
