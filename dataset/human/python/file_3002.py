import collections

N=int(input())
ans=0

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


if N==1:
	print(0)
	
else:
	lis=collections.Counter(prime_factorize(N))
	lis_=list(lis.values())
	for i in range(len(lis_)):
		for h in range(1,45):
			if lis_[i]>=h*(h+1)/2:
				ans+=1
	print(int(ans))
