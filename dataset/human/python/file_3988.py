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
def calc_n_value(i):
  return(int((
    ((i*8+1)**0.5-1)*0.5
  )//1))

n=int(input())
fcts = prime_factorize(n)
tmp = Counter(fcts).values()
out=0
for _ in tmp:
  out += calc_n_value(_)
print(out)
