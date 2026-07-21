from collections import Counter
def factorization(n) -> list:
	ret = []
	i = 2
	while i * i <= n:
		while n % i == 0:
			n //= i
			ret.append(i)
		i += 1
	if n != 1:
		ret.append(n)
	return ret

n=int(input())
if n==1:
	print(0)
	exit()
c=Counter(factorization(n))
ans=0
for x in c.values():
	r=0
	while r*(r+1)//2<=x:
		r+=1
	ans+=r-1
print(ans)
