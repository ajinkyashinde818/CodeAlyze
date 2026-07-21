n = int(input())
def prime_decomposition(n):
  i = 2
  table = []
  while i * i <= n:
    while n % i == 0:
      n /= i
      table.append(i)
    i += 1
  if n > 1:
    table.append(n)
  return table


a = prime_decomposition(n)


d ={}
for i in a:
    if i not in d:
        d[i] = int(0)
    d[i] += 1
    


c = list(d.values())


l =[]
for i in c:
    e = 1
    count = 1
    f = 0
    while i >=  e:
        count += 1
        f += 1 
        e = e + count
    l.append(f)
    
print(sum(l))
