import collections

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
 
N = int(input())

l = collections.Counter(prime_decomposition(N))

ans = 0
for p,c in l.items():
    i = 1
    while c >= i :
        c -=i
        i += 1
        ans +=1

print(ans)
