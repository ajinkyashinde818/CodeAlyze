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
N=int(input())
count = 0
A=prime_factorize(N)
if A==0:print(0)
else:
  B=collections.Counter(A)
  C=list(B.values())
  for i in C:
    for j in range(1,N+1):
      if j*(j+1)//2 <= i < (j+1)*(j+2)//2:
        count +=j
        break
print(count)
