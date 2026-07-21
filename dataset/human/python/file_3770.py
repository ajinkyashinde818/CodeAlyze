import collections
N = int(input())

def prime(n):
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
ans = prime(N)
c = collections.Counter(ans)
count = 0
for i in c.keys():
  if c[i] <= 2:
    count += 1
  elif c[i] <= 5:
    count += 2
  elif c[i] <= 9:
    count += 3
  elif c[i] <= 14:
    count += 4
  elif c[i] <= 20:
    count += 5
  elif c[i] <= 27:
    count += 6
  elif c[i] <= 35:
    count += 7
  elif c[i] <= 44:
    count += 8

print(count)
