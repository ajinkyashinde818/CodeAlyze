def divisor(n): 
    i = 1
    table = []
    while i * i <= n:
        if n%i == 0:
            table.append(i)
            table.append(n//i)
        i += 1
    table = list(set(table))
    return table
def prime_decomposition(n):
  i = 2
  table = []
  while i * i <= n:
    while n % i == 0:
      n //= i
      table.append(i)
    i += 1
  if n > 1:
    table.append(n)
  return table

n = int(input())
a = sorted(divisor(n))
cnt = 0
for i in range(1, len(a)):
    b = prime_decomposition(a[i])
    if len(list(set(b))) == 1:
        if n % a[i] == 0:
            n //= a[i]
            cnt += 1
print(cnt)
