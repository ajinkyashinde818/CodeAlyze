from collections import Counter
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
  
n = int(input())
A = prime_factorize(n)
C = Counter(A)

S = []
s = 0
for i in range(1,50):
  s += i  
  S.append(s)
  
def count(n):
  for i in range(50-1):
    if n < S[i]:
      return i    

ans = 0
for k,v in C.items():
  ans += count(v)
  
print(ans)
