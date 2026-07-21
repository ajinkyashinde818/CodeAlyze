n = int(input())

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

c=list(Counter(prime_factorize(n)).values())

if len(c)==0:
	print(0)
	exit()
ans=0

for i in c:
	for j in range(1,10**7):
		i-=j
		if i>=0:
			ans+=1
		else:
			break

print(ans)
