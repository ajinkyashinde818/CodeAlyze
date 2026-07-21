import collections

def prime_decomposition(n):
  i = 2
  table = []
  while i * i <= n:
    while n % i == 0:
      n /= i
      table.append(int(i))
    i += 1
  if n > 1:
    table.append(int(n))
  return table

countdict = {}
counter = 0

for i in range(1, 10):
    a = int(i*(i+1)/2)
    b = int((i+1)*(i+2)/2)
    for j in range(a, b):
        countdict[j] = i

N = int(input())
primelist = prime_decomposition(N)
primedic = collections.Counter(primelist)
result = 0

for i in primedic.values():
    result += countdict[i]
print(result)
