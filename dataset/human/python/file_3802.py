import collections
N = int(input())
ans = 0

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
  
c = collections.Counter(prime_factorize(N))
so = c.keys()

num = 0
for i in so :
  num =c[i] 
  for j in range(1, num+1):
    if num >= j :
      num -= j
      ans += 1
    else :
      break
      
print(ans)
