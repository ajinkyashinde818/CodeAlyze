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

n=int(input())
c = Counter(prime_factorize(n))
ans=0
N=n
for k,v in c.items():
	x=v
	d=1
	while x-d>=0:
		ans+=1
		x-=d
		d+=1
print(ans)
