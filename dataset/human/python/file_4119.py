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

import collections

N = int(input())
A = collections.Counter(prime_factorize(N))

ans = 0
for a in A.values():
	b = 1
	c = 1
	while True:
		if b > a:
			break
		c+=1
		b = b + c
	ans+=c-1
print(ans)




#import math

#A,B = input().split()



#C = int(int(A) * float(B) * 100)


#print(C // 100)

#N = int(input())
#As = list(map(int,input().split()))

#sum = 1

#if any(b == 0 for b in As):
#	sum = 0
#else:
#	for a in As:
#		sum*=a
#		if sum > 1000000000000000000:
#			sum = -1
#			break
#print(sum)


#A,B=map(int,input().split())

#print(A*B)
